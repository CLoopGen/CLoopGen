#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double alpha;
extern double *x;
extern double *y;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = alpha;
    for (i = 0; i < len; i++) {
        double val = x[i];
        y[i] += temp * val;
    }
}
