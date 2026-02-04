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
    int i;
    for (i = 0; i < len4; i += 2) {
        sum0 += x[4 * i] * y[4 * i];
        sum1 += x[4 * i + 1] * y[4 * i + 1];
        sum2 += x[4 * i + 2] * y[4 * i + 2];
        sum3 += x[4 * i + 3] * y[4 * i + 3];

        if (i + 1 < len4) {
            sum0 += x[4 * (i + 1)] * y[4 * (i + 1)];
            sum1 += x[4 * (i + 1) + 1] * y[4 * (i + 1) + 1];
            sum2 += x[4 * (i + 1) + 2] * y[4 * (i + 1) + 2];
            sum3 += x[4 * (i + 1) + 3] * y[4 * (i + 1) + 3];
        }
    }
}
