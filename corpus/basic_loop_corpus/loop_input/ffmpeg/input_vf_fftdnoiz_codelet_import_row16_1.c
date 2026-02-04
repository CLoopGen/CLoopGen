#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTSample *dst_re_ptr;
FFTSample *dst_im_ptr;
FFTComplex *dst;
int rw;
uint16_t *src;
int j;

void init_vars() {
    rw = 1 << 20; // 1 million elements, approx 4MB for dst (2x float per element) and 2MB for src

    dst = aligned_alloc(32, rw * sizeof(FFTComplex));
    src = aligned_alloc(32, rw * sizeof(uint16_t));

    for (int i = 0; i < rw; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
        dst[i].re = 0.0f;
        dst[i].im = 0.0f;
    }
}