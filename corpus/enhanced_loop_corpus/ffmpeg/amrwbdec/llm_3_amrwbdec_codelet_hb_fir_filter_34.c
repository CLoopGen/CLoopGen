#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float fir_coef[31];
extern int i;
extern int j;
extern float data[110];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Reverse Access Pattern
    // Process the inner loop in reverse order of coefficients and data
    // Access data consecutively but from high to low index
    for (i = 0; i < 80; i++) {
        out[i] = 0.;
        for (j = 30; j >= 0; j--) {  // Reverse iteration over filter taps
            out[i] += data[i + j] * fir_coef[j];
        }
    }
}
