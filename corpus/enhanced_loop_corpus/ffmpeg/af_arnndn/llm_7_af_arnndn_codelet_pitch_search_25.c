#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = (len >> 2) - 1; j >= 0; j--) {
        x_lp4[j] = x_lp[2 * j];
        if (j > 0) {
            x_lp4[j-1] = x_lp[2 * (j-1)]; // Introduces WAW and potential RAW dependency via reuse of j
            j--; // Skip next iteration index to avoid duplication, creating non-trivial loop-carried dependence
        }
    }
}
