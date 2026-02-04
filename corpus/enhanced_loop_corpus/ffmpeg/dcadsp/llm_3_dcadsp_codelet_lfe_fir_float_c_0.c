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
    float temp_buffer[512]; // Local buffer to enable sequential write
    int half_factor = factor / 2;
    for (j = 0; j < half_factor; j++) {
        float a = 0;
        float b = 0;
        const float *fc_a = &filter_coeff[j * ncoeffs];
        const float *fc_b = &filter_coeff[(half_factor - j - 1) * ncoeffs];
        const int32_t *ls = &lfe_samples[-ncoeffs + 1];
        for (k = 0; k < ncoeffs; k++) {
            a += fc_a[k] * ls[k];
            b += fc_b[ncoeffs - 1 - k] * ls[k]; // Reverse filter traversal
        }
        temp_buffer[j] = a;
        temp_buffer[half_factor + j] = b;
    }
    // Sequential write to pcm_samples
    for (int m = 0; m < factor; m++) {
        pcm_samples[m] = temp_buffer[m];
    }
    lfe_samples++;
    pcm_samples += factor;
}
}
