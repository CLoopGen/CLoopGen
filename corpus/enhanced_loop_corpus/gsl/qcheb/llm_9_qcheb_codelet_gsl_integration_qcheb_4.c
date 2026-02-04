#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb24;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double factor = 1. / 12.;
    for (i = 1; i < 48; i++) {
        size_t index = i % 24;
        if (index >= 1) {
            cheb24[index] *= factor;
        }
    }
}
