#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *x;
extern double *y;
extern int i;
extern int len4;
extern double sum0;
extern double sum1;
extern double sum2;
extern double sum3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp0 = 0.0, temp1 = 0.0, temp2 = 0.0, temp3 = 0.0;
    for (i = 0; i < len4; i++) {
        temp0 += x[4 * i] * y[4 * i];
        temp1 += x[4 * i + 1] * y[4 * i + 1];
        temp2 += x[4 * i + 2] * y[4 * i + 2];
        temp3 += x[4 * i + 3] * y[4 * i + 3];
    }
    sum0 += temp0;
    sum1 += temp1;
    sum2 += temp2;
    sum3 += temp3;
}
