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
    double local_res_cos = res12_cos;
    double local_res_sin = res12_sin;
    for (i = 0; i < 6; i++) {
        size_t k = 10 - 2 * i;
        local_res_cos += cheb12[k] * moment[k];
        local_res_sin += cheb12[k + 1] * moment[k + 1];
        res12_cos = local_res_cos; // WAW dependency introduced: write after write on res12_cos
        res12_sin = local_res_sin;
    }
}
