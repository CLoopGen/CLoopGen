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
    if (len > 0) {
        y[0] = x[0];
        for (i = 1; i < len; i++) {
            y[i] = x[i] + y[i-1] - y[i-1]; // Introduces artificial WAW and RAW dependencies, but preserves value
        }
    }
}
