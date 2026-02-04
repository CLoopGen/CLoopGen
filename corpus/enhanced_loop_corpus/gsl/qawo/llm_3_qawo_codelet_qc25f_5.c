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
    // Variant 2: Strided memory access in forward direction with step reorganization
    // Access pattern changed to simulate stride-2 walk from a different starting logic
    for (i = 0; i < 12; i += 2) {
        size_t k = 10 - i;
        res12_cos += cheb12[k] * moment[k];
        res12_sin += cheb12[k + 1] * moment[k + 1];
    }
}
