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
    double inv_d = 1.0 / d;
    for (i = 0; i < n; ++i) {
        x[i] *= inv_d;
    }
}
