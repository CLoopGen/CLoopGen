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
    lfe_samples++;
    for (j = 0; j < factor / 2; j++) {
        float a = 0;
        float b = 0;
        k = 0;
        if (k < ncoeffs) {
            do {
                a += filter_coeff[j * ncoeffs + k] * lfe_samples[-k];
                b += filter_coeff[255 - j * ncoeffs - k] * lfe_samples[-k];
                k++;
            } while (k < ncoeffs);
        }
        pcm_samples[j] = a;
        pcm_samples[factor / 2 + j] = b;
    }
    pcm_samples += factor;
}
}
