#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern  float *coeff;
extern int nsamples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride on samples
    // Here, we modify the inner loop to access 'samples' with a stride of 2,
    // simulating processing of decimated data. Adjust indexing to stay within bounds.
    for (i = 0; i < nsamples; i++) {
        float res = 0;
        int base_idx = i - 1;
        for (j = 0; j < 8; j += 2) { // Stride of 2 in coefficient and sample indexing
            int s_index = base_idx - j;
            if (s_index >= 0) { // Prevent out-of-bounds access
                res += coeff[j] * samples[s_index];
            }
        }
        samples[i] -= res;
    }
}
