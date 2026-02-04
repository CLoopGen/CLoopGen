#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

uint16_t ff_fft_offsets_lut[256];
FFTComplex *z;
int n;
int num_transforms;
int offset;
FFTSample tmp1;
FFTSample tmp2;
FFTSample tmp3;
FFTSample tmp4;
FFTSample tmp5;
FFTSample tmp6;
FFTSample tmp7;
FFTSample tmp8;
FFTComplex *tmpz;

void init_vars() {
    num_transforms = 256;
    for (int i = 0; i < num_transforms; i++) {
        ff_fft_offsets_lut[i] = i * 4;
    }

    size_t total_size = num_transforms * 16;
    z = aligned_alloc(32, total_size * sizeof(FFTComplex));
    if (!z) exit(1);

    for (size_t i = 0; i < total_size; i++) {
        z[i].re = (FFTSample)(i % 128) / 64.0f;
        z[i].im = (FFTSample)((i + 1) % 128) / 64.0f;
    }
}