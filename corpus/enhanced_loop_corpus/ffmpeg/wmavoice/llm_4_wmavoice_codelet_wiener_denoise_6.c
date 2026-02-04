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
        if (n % 2 == 0) {
            float v1 = synth_pf[n * 2], v2 = synth_pf[n * 2 + 1];
            synth_pf[n * 2] = v1 * coeffs[n * 2] - v2 * coeffs[n * 2 + 1];
            synth_pf[n * 2 + 1] = v2 * coeffs[n * 2] + v1 * coeffs[n * 2 + 1];
        } else {
            float v1 = synth_pf[n * 2];
            float v2 = synth_pf[n * 2 + 1];
            float c1 = coeffs[n * 2];
            float c2 = coeffs[n * 2 + 1];
            synth_pf[n * 2] = v1 * c1;
            synth_pf[n * 2 + 1] = v2 * c2;
        }
    }
}
