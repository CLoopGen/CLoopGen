#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern double bandwidth_expansion_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[10];
    for (i = 0; i < 10; i++) {
        temp[i] = lpc[i] * bandwidth_expansion_coeff;
        bandwidth_expansion_coeff *= 0.98829999999999996;
    }
    for (i = 0; i < 10; i++) {
        lpc[i] = temp[i];
    }
}
