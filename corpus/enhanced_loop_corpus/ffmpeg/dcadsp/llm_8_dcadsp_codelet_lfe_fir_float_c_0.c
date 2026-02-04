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
        int idx1 = j * ncoeffs;
        int idx2 = (factor / 2 - 1 - j) * ncoeffs;
        for (k = 0; k < ncoeffs; k++) {
            float coef1 = filter_coeff[idx1 + k];
            float coef2 = filter_coeff[idx2 + ncoeffs - 1 - k];
            int lfe_idx = -k;
            a += coef1 * lfe_samples[lfe_idx];
            b += coef2 * lfe_samples[lfe_idx];
        }
        pcm_samples[j] = a;
        pcm_samples[factor / 2 + j] = b;
    }
    lfe_samples++;
    pcm_samples += factor;
}
}
