#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *arr1;
float *arr2;
int len;
float err;
int i;

void init_vars() {
    const int target_time_ns = 10000000; // 10 ms in nanoseconds
    struct timespec start, end;

    // Estimate overhead of empty loop
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < 1000000; i++) {}
    clock_gettime(CLOCK_MONOTONIC, &end);
    long empty_loop_time = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
    double cycles_per_iter = empty_loop_time / 1000000.0;

    // Target number of iterations for ~10ms
    long target_iters = (long)(target_time_ns / (cycles_per_iter * 3)); // Rough estimate of work per iteration

    // Clamp to reasonable memory bounds (1MB to 256MB for two float arrays)
    size_t min_size = 1 << 18;  // ~1M floats total (4MB)
    size_t max_size = 1 << 26;  // ~67M floats (256MB total)
    len = (int)(target_iters < (long)min_size ? min_size :
                target_iters > (long)max_size ? max_size : target_iters);

    // Allocate arrays
    arr1 = (float*)aligned_alloc(32, len * sizeof(float));
    arr2 = (float*)aligned_alloc(32, len * sizeof(float));

    // Initialize arrays with random data
    srand(0);
    for (int j = 0; j < len; j++) {
        arr1[j] = (float)((double)rand() / RAND_MAX * 2.0 - 1.0); // [-1, 1]
        arr2[j] = (float)((double)rand() / RAND_MAX * 2.0 - 1.0); // [-1, 1]
    }

    err = 0.0f;
}