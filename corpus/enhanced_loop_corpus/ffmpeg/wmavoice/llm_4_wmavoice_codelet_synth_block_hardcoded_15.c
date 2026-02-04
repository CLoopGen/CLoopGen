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
    for (n = 0; n < size; n++) {
        if (r_idx + n >= 0 && r_idx + n < 1000) {
            excitation[n] = wmavoice_std_codebook[r_idx + n] * gain;
        }
    }
}
