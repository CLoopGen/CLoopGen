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
    // Variant 2: Reverse Consecutive Memory Access
    int idx;
    for (n = 0; n < size; n++) {
        idx = size - 1 - n; // reverse index
        excitation[idx] = wmavoice_std_codebook[r_idx + idx] * gain;
    }
}
