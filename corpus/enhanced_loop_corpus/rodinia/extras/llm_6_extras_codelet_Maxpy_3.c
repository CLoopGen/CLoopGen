#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double alpha;
extern double *x;
extern double *y;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1, temp2, temp3, temp4;
    for (i = 0; i < len4; i++) {
        temp1 = alpha * x[4 * i];
        temp2 = alpha * x[4 * i + 1];
        temp3 = alpha * x[4 * i + 2];
        temp4 = alpha * x[4 * i + 3];
        y[4 * i] += temp1;
        y[4 * i + 1] += temp2;
        y[4 * i + 2] += temp3;
        y[4 * i + 3] += temp4;
    }
}
