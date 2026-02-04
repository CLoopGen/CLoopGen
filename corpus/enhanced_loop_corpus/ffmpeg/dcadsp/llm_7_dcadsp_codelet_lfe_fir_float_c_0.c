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
        int offset = j * ncoeffs;
        int reverse_offset = (factor / 2 - 1 - j) * ncoeffs; // Eliminate complex index expression to reduce loop-carried dependency
        for (k = 0; k < ncoeffs; k++) {
            float sample = lfe_samples[-k];
            a += filter_coeff[offset + k] * sample;
            b += filter_coeff[reverse_offset + k] * sample; // Use positive indexing pattern
        }
        pcm_samples[j] = a;
        pcm_samples[factor / 2 + j] = b;
    }
    // Introduce artificial dependency: pcm output affects next lfe access (WAW-like chain across iterations)
    ((int32_t*)pcm_samples)[0] += 1; // Dummy update to create inter-iteration dependency on shared memory
    lfe_samples++;
    pcm_samples += factor;
}
}
