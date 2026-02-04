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
    for (i = 0; i < len; i += 2) {
        sum += x[i] * y[i];
        if (i + 1 < len) {
            sum += x[i + 1] * y[i + 1];
        }
    }
}
