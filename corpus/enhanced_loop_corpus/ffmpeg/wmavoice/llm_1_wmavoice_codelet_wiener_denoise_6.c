#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *synth_pf;
extern int n;
extern float *coeffs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 1; n < 64; n++) {
    for (int unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
        float v1 = synth_pf[n * 2], v2 = synth_pf[n * 2 + 1];
        synth_pf[n * 2] = v1 * coeffs[n * 2] - v2 * coeffs[n * 2 + 1];
        synth_pf[n * 2 + 1] = v2 * coeffs[n * 2] + v1 * coeffs[n * 2 + 1];
    }
}
}
