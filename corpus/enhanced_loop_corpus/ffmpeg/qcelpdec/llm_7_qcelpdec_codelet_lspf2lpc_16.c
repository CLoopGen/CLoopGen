#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern double bandwidth_expansion_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double coeff = bandwidth_expansion_coeff;
    for (i = 0; i < 10; i++) {
        lpc[i] *= coeff;
        coeff *= 0.98829999999999996;
    }
    bandwidth_expansion_coeff = coeff;
}
