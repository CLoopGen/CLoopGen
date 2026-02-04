#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *moment;
extern double cheb12[13];
extern double res12_cos;
extern double res12_sin;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        size_t k1 = 10 - 2 * i;
        size_t k2 = 8 - 2 * i;
        res12_cos += cheb12[k1] * moment[k1] + cheb12[k2] * moment[k2];
        res12_sin += cheb12[k1 + 1] * moment[k1 + 1] + cheb12[k2 + 1] * moment[k2 + 1];
    }
}
