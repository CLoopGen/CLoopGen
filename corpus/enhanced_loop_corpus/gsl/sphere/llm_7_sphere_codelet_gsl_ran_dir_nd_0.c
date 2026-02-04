#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t n;
extern double *x;
extern double d;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        x[0] /= d;
        for (i = 1; i < n; ++i) {
            x[i] = x[i-1] + (x[i] / d);
        }
    }
}
