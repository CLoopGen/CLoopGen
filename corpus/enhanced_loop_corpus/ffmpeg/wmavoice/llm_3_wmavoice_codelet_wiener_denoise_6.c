#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *synth_pf;
extern int n;
extern float *coeffs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with step unrolling and temporary storage for better locality
    float temp_real, temp_imag;
    for (int stride = 2; stride <= 126; stride += 4) {  // Access every 2nd complex pair (strided)
        int idx = stride;
        float v1 = synth_pf[idx], v2 = synth_pf[idx + 1];
        temp_real = v1 * coeffs[idx] - v2 * coeffs[idx + 1];
        temp_imag = v2 * coeffs[idx] + v1 * coeffs[idx + 1];
        synth_pf[idx] = temp_real;
        synth_pf[idx + 1] = temp_imag;
    }
}
