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
    // Variant 1: Consecutive Memory Access (unrolled and restructured for sequential access)
    int i;
    for (i = 0; i < len4 * 4; i += 4) {
        sum0 += x[i] * y[i];
        sum1 += x[i + 1] * y[i + 1];
        sum2 += x[i + 2] * y[i + 2];
        sum3 += x[i + 3] * y[i + 3];
    }
}
