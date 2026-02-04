#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *histogram;
extern double *scale_histogram;
extern double alpha;
extern double *gamma;
extern double sum;
extern ssize_t u;
extern ssize_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum[256];
    for (x = 0; x <= 255; x++) {
        temp_sum[x] = 0.0;
        for (u = 0; u <= 255; u++) {
            ssize_t offset = (x - u);
            if (offset < 0) offset = -offset;
            temp_sum[x] += (double)histogram[u] * gamma[offset];
        }
    }
    for (x = 0; x <= 255; x++) {
        scale_histogram[x] = alpha * temp_sum[x];
    }
}
