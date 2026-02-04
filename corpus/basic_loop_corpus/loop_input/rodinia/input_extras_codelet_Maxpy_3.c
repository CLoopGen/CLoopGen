#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

double alpha;
double *x;
double *y;
int i;
int len4;

void init_vars() {
    const long target_time_us = 10000; // 0.01 seconds in microseconds
    const double cpu_freq_gigahertz = 2.5;
    const long operations_per_iteration = 8;
    const long bytes_per_iteration = 64; 

    long len_est = (target_time_us * 1000) / (operations_per_iteration);
    len4 = (len_est + 3) / 4 * 4;
    if (len4 < 1000) len4 = 1000;

    size_t data_size_bytes = 4 * len4 * sizeof(double);
    x = (double*)aligned_alloc(32, data_size_bytes);
    y = (double*)aligned_alloc(32, data_size_bytes);

    if (!x || !y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    alpha = 1.5;
    for (int j = 0; j < 4 * len4; j++) {
        x[j] = (double)(j % 1000) / 100.0;
        y[j] = (double)(j % 500) / 50.0;
    }
}