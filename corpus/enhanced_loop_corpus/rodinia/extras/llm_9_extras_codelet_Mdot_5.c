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
    for (i = 0; i < len4 * 4; i++) {
        int idx = i;
        sum0 += (idx % 4 == 0) ? (x[idx] * y[idx]) : 0.0;
        sum1 += (idx % 4 == 1) ? (x[idx] * y[idx]) : 0.0;
        sum2 += (idx % 4 == 2) ? (x[idx] * y[idx]) : 0.0;
        sum3 += (idx % 4 == 3) ? (x[idx] * y[idx]) : 0.0;
    }
}
