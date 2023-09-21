#include "../../includes/philo.h"

void milisecond_counter(int ms)
{
	struct timespec start_time, current_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    while (1) {
        clock_gettime(CLOCK_MONOTONIC, &current_time);
        if ((current_time.tv_sec - start_time.tv_sec) * 1000 +
            (current_time.tv_nsec - start_time.tv_nsec) / 1000000 >= ms) {
            printf("geçen süre :%d ms\n", ms);
            break;
        }
    }
	
}	

void second_counter(int seconds)
{
    time_t start_time = time(NULL);
    while (1) {
        time_t current_time = time(NULL);
        if (current_time - start_time >= seconds) {
            printf("geçen süre :%d saniye\n", seconds);
            break;
        }
    }
}
