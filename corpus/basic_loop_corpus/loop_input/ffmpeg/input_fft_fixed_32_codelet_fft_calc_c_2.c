#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

#define NUM_TRANSFORMS 65536

uint16_t ff_fft_offsets_lut[NUM_TRANSFORMS];
FFTComplex *z;
int num_transforms;
int n;
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

void init_vars() {
    num_transforms = NUM_TRANSFORMS;
    
    for (int i = 0; i < num_transforms; i++) {
        ff_fft_offsets_lut[i] = i * 4;
    }

    z = aligned_alloc(32, sizeof(FFTComplex) * (num_transforms * 4 + 16));
    
    for (int i = 0; i < num_transforms * 4 + 16; i++) {
        z[i].re = rand() % 1000;
        z[i].im = rand() % 1000;
    }
}