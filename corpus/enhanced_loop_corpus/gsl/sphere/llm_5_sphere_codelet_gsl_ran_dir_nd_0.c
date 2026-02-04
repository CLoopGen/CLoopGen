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
    for (i = 0; i < n; ++i) {
        if (x[i] != 0.0) {
            x[i] /= d;
        }
    }
}
