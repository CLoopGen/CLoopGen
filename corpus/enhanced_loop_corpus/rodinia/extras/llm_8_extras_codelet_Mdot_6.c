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
    int stride = 2;
    for (i = 0; i < len; i += stride) {
        if (i + 1 < len) {
            sum += x[i] * y[i] + x[i + 1] * y[i + 1];
        } else {
            sum += x[i] * y[i];
        }
    }
}
