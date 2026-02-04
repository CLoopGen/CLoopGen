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
    double factor = alpha;
    for (i = 0; i < len4; i++) {
        y[4 * i] = y[4 * i] + factor * x[4 * i];
        factor = y[4 * i] * 0.001; // Introduce artificial loop-carried WAW and RAW dependency
        y[4 * i + 1] = y[4 * i + 1] + factor * x[4 * i + 1];
        y[4 * i + 2] = y[4 * i + 2] + factor * x[4 * i + 2];
        y[4 * i + 3] = y[4 * i + 3] + factor * x[4 * i + 3];
    }
}
