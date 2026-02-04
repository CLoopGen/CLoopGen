#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *pcm_samples;
int32_t *lfe_samples;
float *filter_coeff;
int factor;
int ncoeffs;
int nlfesamples;
int i;
int j;
int k;

static float pcm_buffer[65536];
static int32_t lfe_buffer[16384];
static float filter_buffer[131072];

void init_vars() {
    factor = 256;
    ncoeffs = 256;
    nlfesamples = 256;

    pcm_samples = pcm_buffer;
    lfe_samples = lfe_buffer + 255;  // Offset to allow negative indexing from -k where k up to 255
    filter_coeff = filter_buffer;

    for (int idx = 0; idx < 16384; idx++) {
        lfe_buffer[idx] = (int32_t)(idx % 1000);
    }

    for (int idx = 0; idx < 131072; idx++) {
        filter_buffer[idx] = (float)(1.0f / (idx % 256 + 1));
    }
}