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
    double temp_sum = 0.0;
    for (i = 0; i < len; i++) {
        temp_sum += x[i] * y[i];
    }
    sum += temp_sum;
}
