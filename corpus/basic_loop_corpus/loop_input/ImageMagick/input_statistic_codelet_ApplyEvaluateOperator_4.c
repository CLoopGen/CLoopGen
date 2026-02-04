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
    
    double elapsed = 0.0;
    ssize_t count = 0;
    
    while (elapsed < 0.01) {
        count += 100000;
        value = (double)count;
        result = 1.0;
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (i = 0; i < (ssize_t)value; i++)
            result *= 2.;
        clock_gettime(CLOCK_MONOTONIC, &end);
        
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    }
    
    value = (double)count;
    result = 1.0;
}