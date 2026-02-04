#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float wmavoice_std_codebook[1000];
extern int size;
extern float *excitation;
extern float gain;
extern int n;
extern int r_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float g_sq = gain * gain;
    for (n = 0; n < size * 2; n++) {
        int idx = r_idx + (n % size);
        int e_idx = n % size;
        float temp = wmavoice_std_codebook[idx] * g_sq;
        excitation[e_idx] += temp * 0.5f; // Accumulate scaled value
    }
}
