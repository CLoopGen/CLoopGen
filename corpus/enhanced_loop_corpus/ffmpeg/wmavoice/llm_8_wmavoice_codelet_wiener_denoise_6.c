#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *synth_pf;
extern int n;
extern float *coeffs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 1; n < 32; n++) {
    float v1 = synth_pf[n * 4], v2 = synth_pf[n * 4 + 1];
    float c1 = coeffs[n * 4], c2 = coeffs[n * 4 + 1];
    synth_pf[n * 4] = v1 * c1 - v2 * c2;
    synth_pf[n * 4 + 1] = v2 * c1 + v1 * c2;
}
}
