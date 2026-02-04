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
    float temp_gain = gain;
    float *local_excitation = excitation;
    const float *codebook = wmavoice_std_codebook;
    int idx_offset = r_idx;
    for (n = 0; n < size; n++) {
        float codebook_val = codebook[idx_offset + n];
        local_excitation[n] = codebook_val * temp_gain;
    }
}
