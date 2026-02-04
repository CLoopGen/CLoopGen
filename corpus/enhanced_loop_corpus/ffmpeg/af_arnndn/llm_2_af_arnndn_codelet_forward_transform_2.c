#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern  float *in;
extern AVComplexFloat x[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 4
    for (int i = 0; i < (2 * (120 << 2)); i += 4) {
        for (int j = 0; j < 4 && (i + j) < (2 * (120 << 2)); j++) {
            int idx = i + j;
            x[idx].re = in[idx];
            x[idx].im = 0;
        }
    }
}
