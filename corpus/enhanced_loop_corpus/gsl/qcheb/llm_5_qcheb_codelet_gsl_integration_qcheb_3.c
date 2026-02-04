#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 12; i++) {
        if (cheb12[i] > 0.0) {
            cheb12[i] *= 1. / 6.;
            continue;
        }
        cheb12[i] = 0.0;
    }
}
