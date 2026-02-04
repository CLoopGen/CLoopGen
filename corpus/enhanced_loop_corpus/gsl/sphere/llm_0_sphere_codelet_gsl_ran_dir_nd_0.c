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
    for (size_t j = 0; j < n; ++j) {
        for (i = j; i < j + 1; ++i) {
            x[i] /= d;
        }
    }
}
