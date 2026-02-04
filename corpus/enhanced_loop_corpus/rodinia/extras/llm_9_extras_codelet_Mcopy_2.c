#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double a = 1.0, b = 2.0, c = 0.5;
    for (i = 0; i < len; i++) {
        y[i] = a * x[i] + b;
        y[i] = y[i] * c;
    }
}
