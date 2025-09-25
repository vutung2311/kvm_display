#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <getopt.h>
#include "ctrl.h"
#include "screen.h"
#include "update.h"

#include <sys/ioctl.h>
#include <linux/nbd.h>

volatile bool running = true;

void handle_signal(int signal)
{
    if (running == false)
    {
        return;
    }
    running = false;
    printf("[kvm_display] Caught signal %d, stopping\n", signal);
    stop_ctrl_loop();
    printf("[kvm_display] Stopped control loop\n");
    stopupdate();
    printf("[kvm_display] Stopped monitor update\n");
}

int main(int argc, char **argv)
{
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, run_monitor_loop, NULL);
    pthread_detach(monitor_thread);

    init_lvgl();
    printf("[kvm_display] creating screen_thread\n");
    pthread_t screen_thread;
    pthread_create(&screen_thread, NULL, run_lvgl_loop, NULL);
    pthread_detach(screen_thread);

    if (connect_ctrl_client("/var/run/kvm_display.sock") != 0)
    {
        printf("[kvm_display] can not connect to ctrl server\n");
        return -1;
    }
    start_ctrl_loop();

    while (running)
    {
        // TODO: use pthread primitives
        //  Sleep for a short interval to avoid busy-waiting
        usleep(1000000); // Sleep for 100ms
    }
    return 0;
}
