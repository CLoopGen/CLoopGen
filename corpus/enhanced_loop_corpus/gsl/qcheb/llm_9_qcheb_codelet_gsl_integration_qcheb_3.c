#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 12; i += 2) {
        double temp = cheb12[i] * (1. / 6.);
        cheb12[i - 1] *= (1. / 6.);
        cheb12[i] = temp;
    }
}
