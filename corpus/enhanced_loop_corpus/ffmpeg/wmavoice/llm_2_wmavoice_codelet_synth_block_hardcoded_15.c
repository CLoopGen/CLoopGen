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
    // Variant 1: Strided Memory Access (stride of 2)
    for (n = 0; n < size; n += 2) {
        if (r_idx + n < 1000) // bounds check for codebook access
            excitation[n] = wmavoice_std_codebook[r_idx + n] * gain;
        if (n + 1 < size && r_idx + n + 1 < 1000)
            excitation[n + 1] = wmavoice_std_codebook[r_idx + n + 1] * gain;
    }
}
