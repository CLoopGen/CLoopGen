#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum1 = 0.0;
    double local_sum2 = 0.0;
    int stride = 2;
    for (i = 0; i < len - 1; i += stride) {
        local_sum1 += x[i] * y[i];
        local_sum2 += x[i+1] * y[i+1];
    }
    if (i < len) {
        local_sum1 += x[i] * y[i];
    }
    sum += (local_sum1 + local_sum2);
}
