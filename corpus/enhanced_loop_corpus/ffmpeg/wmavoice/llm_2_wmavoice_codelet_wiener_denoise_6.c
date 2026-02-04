#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *synth_pf;
extern int n;
extern float *coeffs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base offset precomputation
    float *pf_base = &synth_pf[2];
    float *cf_base = &coeffs[2];
    for (int i = 0; i < 63; i++) {
        float v1 = pf_base[i * 2 - 2];  // Equivalent to synth_pf[2*(i+1)]
        float v2 = pf_base[i * 2 - 1];
        pf_base[i * 2 - 2] = v1 * cf_base[i * 2 - 2] - v2 * cf_base[i * 2 - 1];
        pf_base[i * 2 - 1] = v2 * cf_base[i * 2 - 2] + v1 * cf_base[i * 2 - 1];
    }
}
