#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pcm_samples;
extern int32_t *lfe_samples;
extern  float *filter_coeff;
extern int factor;
extern int ncoeffs;
extern int nlfesamples;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nlfesamples; i++) {
    for (j = 0; j < factor / 2; j++) {
        float a = 0;
        float b = 0;
        int32_t *lfe_ptr = &lfe_samples[-ncoeffs + 1]; // Reverse indexing base
        for (k = 0; k < ncoeffs; k++) {
            int idx = j * ncoeffs + k;
            a += filter_coeff[idx] * lfe_ptr[k];
            b += filter_coeff[(factor/2 - 1 - j) * ncoeffs + (ncoeffs - 1 - k)] * lfe_ptr[k];
        }
        pcm_samples[j] = a;
        pcm_samples[factor / 2 + j] = b;
    }
    lfe_samples++;
    pcm_samples += factor;
}
}
