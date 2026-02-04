#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

size_t K;
size_t i;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long long start_time = tv.tv_sec * 1000000ULL + tv.tv_usec;

    // Estimate loop overhead to calibrate K
    volatile size_t temp_i;
    int calibration_loops = 1000000;
    gettimeofday(&tv, NULL);
    unsigned long long before = tv.tv_sec * 1000000ULL + tv.tv_usec;

    for (temp_i = 0; temp_i < calibration_loops; temp_i++) {
        __asm__ volatile(""); // Prevent optimization
    }

    gettimeofday(&tv, NULL);
    unsigned long long after = tv.tv_sec * 1000000ULL + tv.tv_usec;
    double time_per_iter = (after - before) / (double)calibration_loops;

    // Target approximately 10000 microseconds (0.01 seconds)
    double target_iters = 10000.0 / time_per_iter;
    K = (size_t)(target_iters < 1 ? 1 : target_iters);

    // Ensure K is at least 1 and within reasonable bounds
    if (K == 0) K = 1;
}