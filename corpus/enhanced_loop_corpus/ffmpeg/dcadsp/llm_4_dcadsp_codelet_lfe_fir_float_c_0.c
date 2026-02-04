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
        if (j % 2 == 0) {
            for (k = 0; k < ncoeffs; k++) {
                a += filter_coeff[j * ncoeffs + k] * lfe_samples[-k];
            }
            for (k = 0; k < ncoeffs; k++) {
                b += filter_coeff[255 - j * ncoeffs - k] * lfe_samples[-k];
            }
        } else {
            for (k = 0; k < ncoeffs; k++) {
                int idx = j * ncoeffs + k;
                a += (idx < 256) ? filter_coeff[idx] * lfe_samples[-k] : 0;
                b += (255 - idx >= 0) ? filter_coeff[255 - idx] * lfe_samples[-k] : 0;
            }
        }
        pcm_samples[j] = a;
        pcm_samples[factor / 2 + j] = b;
    }
    lfe_samples++;
    pcm_samples += factor;
}
}
