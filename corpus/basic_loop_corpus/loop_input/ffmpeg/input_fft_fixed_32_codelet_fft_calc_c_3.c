#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

uint16_t ff_fft_offsets_lut[32];
FFTComplex *z;
int n;
int num_transforms;
int offset;
unsigned int tmp1;
unsigned int tmp2;
unsigned int tmp3;
unsigned int tmp4;
unsigned int tmp5;
unsigned int tmp6;
unsigned int tmp7;
unsigned int tmp8;
FFTComplex *tmpz;
int64_t accu;

void init_vars() {
    num_transforms = 32;
    for (int i = 0; i < num_transforms; i++) {
        ff_fft_offsets_lut[i] = i * 8;
    }

    z = aligned_alloc(32, sizeof(FFTComplex) * 256 * 8);
    if (!z) exit(1);

    for (int i = 0; i < 256 * 8; i++) {
        z[i].re = (int32_t)(i * 17 + 1);
        z[i].im = (int32_t)(i * 997);
    }

    n = 0;
    offset = 0;
    tmp1 = tmp2 = tmp3 = tmp4 = tmp5 = tmp6 = tmp7 = tmp8 = 0;
    accu = 0;
    tmpz = z;
}