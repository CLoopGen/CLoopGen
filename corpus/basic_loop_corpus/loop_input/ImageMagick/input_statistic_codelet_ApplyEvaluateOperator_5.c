#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

double value;
double result;
ssize_t i;

void init_vars() {
    struct timespec start, end;
    double elapsed;

    result = 1.0e30;

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (i = 0; i < 1000000; i++) {
        result /= 2.0;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    value = 1000000.0 * (0.01 / (elapsed > 0 ? elapsed : 1e-9));

    result = 1.0e30;
}