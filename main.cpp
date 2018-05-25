#include "mbed.h"

#if !defined(MBED_CPU_STATS_ENABLED) || !defined(DEVICE_LOWPOWERTIMER) || !defined(DEVICE_SLEEP)
#error [NOT_SUPPORTED] test not supported
#endif

DigitalOut led1(LED1);

#define MAX_THREAD_STACK        384
#define SAMPLE_TIME             1000
#define LOOP_TIME               3000

uint64_t prev_idle_time = 0;
int32_t wait_time = 5000;

void busy_thread()
{
    volatile uint64_t i = ~0;

    while(i--) {
        led1 = !led1;
        wait_us(wait_time);
    }
}

void print_stats()
{
    mbed_stats_cpu_t stats;
    mbed_stats_cpu_get(&stats);

    printf("%-20lld", stats.uptime);
    printf("%-20lld", stats.idle_time);
    printf("%-20lld", stats.sleep_time);
    printf("%-20lld\n", stats.deep_sleep_time);
}

int main()
{
    // Request the shared queue
    EventQueue *stats_queue = mbed_event_queue();
    Thread *thread;
    int id;

    id = stats_queue->call_every(SAMPLE_TIME, print_stats);
    printf("%-20s%-20s%-20s%-20s\n", "Uptime", "Idle Time", "Sleep time", "DeepSleep time");

    thread = new Thread(osPriorityNormal, MAX_THREAD_STACK);
    thread->start(busy_thread);

    // Steadily increase the system load
    for (int count = 1; ; count++) {
        Thread::wait(LOOP_TIME);
        if (wait_time <= 0) {
            break;
        }
        wait_time -= 1000;
    }
    thread->terminate();
    stats_queue->cancel(id);
    return 0;
}
