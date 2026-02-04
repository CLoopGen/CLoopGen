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
        float value = wmavoice_std_codebook[r_idx + n];
        if (value != 0.0f) {
            excitation[n] = value * gain;
        } else {
            excitation[n] = 0.0f;
        }
    }
}
