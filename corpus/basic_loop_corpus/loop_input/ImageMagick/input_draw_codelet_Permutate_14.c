#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

ssize_t n;
ssize_t k;
double r;
ssize_t i;

void init_vars() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    k = 1;
    r = 1.0;
    ssize_t test_n = 1000000; 

    for (ssize_t iter = k + 1; iter <= test_n; iter++) {
        r *= iter;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    if (elapsed > 0) {
        n = (ssize_t)(test_n * (0.01 / elapsed));
    } else {
        n = test_n;
    }

    if (n <= k) n = k + 1;

    r = 1.0;
}