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
for (i = 0; i < nlfesamples; i += 2) {
    if (i + 1 >= nlfesamples) break;
    for (j = 0; j < factor / 4; j++) {
        float a1 = 0, b1 = 0;
        float a2 = 0, b2 = 0;
        for (k = 0; k < ncoeffs; k++) {
            a1 += filter_coeff[j * ncoeffs + k] * lfe_samples[-k];
            b1 += filter_coeff[255 - j * ncoeffs - k] * lfe_samples[-k];
            a2 += filter_coeff[(j + 1) * ncoeffs + k] * lfe_samples[-k];
            b2 += filter_coeff[255 - (j + 1) * ncoeffs - k] * lfe_samples[-k];
        }
        pcm_samples[j] = a1;
        pcm_samples[factor / 2 + j] = b1;
        pcm_samples[j + 1] = a2;
        pcm_samples[factor / 2 + j + 1] = b2;
    }
    lfe_samples += 2;
    pcm_samples += 2 * factor;
}
}
