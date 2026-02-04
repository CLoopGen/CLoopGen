#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern double bandwidth_expansion_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 2; depth1++) {
        for (i = 0; i < 10; i++) {
            lpc[i] *= bandwidth_expansion_coeff;
            bandwidth_expansion_coeff *= 0.98829999999999996;
        }
    }
}
