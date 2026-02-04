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
    float v1 = synth_pf[n * 2], v2 = synth_pf[n * 2 + 1];
    float c1 = coeffs[n * 2], c2 = coeffs[n * 2 + 1];
    float t1 = v1 * c1 - v2 * c2;
    float t2 = v2 * c1 + v1 * c2;
    synth_pf[n * 2] = t1 * c1 + t2 * c2;
    synth_pf[n * 2 + 1] = t2 * c1 - t1 * c2;
}
}
