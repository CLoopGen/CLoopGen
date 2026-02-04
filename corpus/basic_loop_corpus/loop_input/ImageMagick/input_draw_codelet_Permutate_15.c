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
    
    r = 1e15; 
    k = 10;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    ssize_t trial_n = 1000000;
    double temp_r = r;
    for (i = 1; i <= (trial_n - k); i++) {
        temp_r /= i;
        if (fabs(temp_r) < 1e-300) break;
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    
    if (elapsed == 0) {
        n = 2000000;
    } else {
        double target = 0.01;
        n = (ssize_t)(trial_n * target / elapsed);
        if (n < 1000) n = 1000;
        if (n > 10000000) n = 10000000;
    }
    
    r = 1e15;
}