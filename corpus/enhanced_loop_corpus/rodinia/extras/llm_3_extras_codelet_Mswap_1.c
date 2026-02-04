#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (processing array from end to start)
    for (i = len - 1; i >= 0; i--) {
        tmp = x[i];
        x[i] = y[i];
        y[i] = tmp;
    }
}
