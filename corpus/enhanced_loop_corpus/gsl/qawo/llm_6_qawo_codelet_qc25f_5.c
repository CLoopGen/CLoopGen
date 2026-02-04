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
    double temp_cos = 0.0;
    double temp_sin = 0.0;
    for (i = 0; i < 6; i++) {
        size_t k = 10 - 2 * i;
        temp_cos += cheb12[k] * moment[k];
        temp_sin += cheb12[k + 1] * moment[k + 1];
    }
    res12_cos = temp_cos;
    res12_sin = temp_sin;
}
