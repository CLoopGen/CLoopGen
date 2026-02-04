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
    double temp_sum1 = 0.0, temp_sum2 = 0.0;
    for (i = 0; i < len; i++) {
        temp_sum1 += x[i] * y[i];
        temp_sum2 += (x[i] + 1.0) * (y[i] - 1.0);
    }
    sum += temp_sum1 + temp_sum2;
}
