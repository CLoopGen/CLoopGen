#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

double a;
double x;
double sum;
double term;
int n;
int nlow;

void init_vars() {
    a = 2.0;
    x = 1.5;
    sum = 0.0;
    term = 1.0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // Measure time for a small number of iterations
    int temp_nlow = 1000;
    for (n = 1; n < temp_nlow; n++) {
        term *= x / (a + n);
        sum += term;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

    // Target approximately 0.01 seconds (10,000,000 ns)
    long long target_time_ns = 10000000;

    if (elapsed_ns == 0) {
        nlow = 1000000; // Fallback if timing measurement was zero
    } else {
        nlow = (int)((target_time_ns / elapsed_ns) * temp_nlow);
    }

    // Reset variables for actual loop execution
    sum = 0.0;
    term = 1.0;
}