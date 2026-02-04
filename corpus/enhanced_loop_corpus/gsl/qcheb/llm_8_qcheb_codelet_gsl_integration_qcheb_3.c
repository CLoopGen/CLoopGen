#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 1; i < 12; i++) {
        cheb12[i] *= 1. / 6.;
        cheb12[i] += 0.1;
        cheb12[i] -= 0.05;
    }
    for (j = 0; j < 5; j++) {
        cheb12[0] += j * 0.01;
    }
}
