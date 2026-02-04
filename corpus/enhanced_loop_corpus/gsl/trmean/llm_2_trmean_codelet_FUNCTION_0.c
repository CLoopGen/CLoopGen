#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using an array to accumulate values
    double *mean_arr = (double*)malloc((ihigh - ilow + 1) * sizeof(double));
    double delta;
    size_t idx = 0;
    for (i = ilow; i <= ihigh; ++i) {
        k += 1.;
        mean_arr[idx] = delta / k;
        mean += mean_arr[idx];
        idx++;
    }
    free(mean_arr);
}
