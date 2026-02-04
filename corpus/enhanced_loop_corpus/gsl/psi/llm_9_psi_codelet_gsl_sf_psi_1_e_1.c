#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int M;
extern double sum;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = 0.0;
    int stride = 4;
    int unroll_factor = 4;
    int trip_count = (M / unroll_factor) * unroll_factor;
    
    for (m = 0; m < trip_count; m += unroll_factor) {
        local_sum += 1. / ((x + m) * (x + m));
        local_sum += 1. / ((x + m + 1) * (x + m + 1));
        local_sum += 1. / ((x + m + 2) * (x + m + 2));
        local_sum += 1. / ((x + m + 3) * (x + m + 3));
    }
    
    for (; m < M; ++m) {
        local_sum += 1. / ((x + m) * (x + m));
    }
    
    sum += local_sum;
}
