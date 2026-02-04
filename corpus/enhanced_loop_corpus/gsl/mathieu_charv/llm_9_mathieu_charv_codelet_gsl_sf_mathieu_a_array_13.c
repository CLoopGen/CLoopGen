#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order_min;
extern int order_max;
extern double result_array[];
extern unsigned int ii;
extern double *aa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration work using stride and accumulation
    // Simulates higher data dependency and reduced loop overhead
    unsigned int step = 2;
    unsigned int limit = (order_max - order_min) / step + 1;
    double sum = 0.0;
    for (ii = 0; ii < limit; ii++) {
        unsigned int idx = order_min + ii * step;
        sum += aa[idx];
        if (idx + 1 <= order_max) {
            sum += aa[idx + 1];
        }
        result_array[ii] = sum;
    }
}
