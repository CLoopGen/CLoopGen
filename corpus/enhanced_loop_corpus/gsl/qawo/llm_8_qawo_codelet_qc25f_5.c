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
    for (i = 0; i < 12; i += 2) {
        size_t k = 10 - i;
        res12_cos += cheb12[k] * moment[k];
        if (k >= 2) {
            res12_sin += cheb12[k - 1] * moment[k - 1];
        }
    }
}
