#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

typedef int FFTDouble;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern  FFTSample *input;
extern int i;
extern int j;
extern int n;
extern int n8;
extern int n4;
extern int n2;
extern int n3;
extern FFTDouble re;
extern FFTDouble im;
extern  uint16_t *revtab;
extern  FFTSample *tcos;
extern  FFTSample *tsin;
extern FFTComplex *x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n8; i++) {
    FFTDouble re1, im1, re2, im2;
    int j1, j2;

    // First computation block: split dependencies by precomputing re/im values
    re1 = ((int)((-input[2 * i + n3]) + (unsigned int)(-input[n3 - 1 - 2 * i]) + 32) >> 6);
    im1 = ((int)((-input[n4 + 2 * i]) + (unsigned int)(+input[n4 - 1 - 2 * i]) + 32) >> 6);
    j1 = revtab[i];

    re2 = ((int)((input[2 * i]) + (unsigned int)(-input[n2 - 1 - 2 * i]) + 32) >> 6);
    im2 = ((int)((-input[n2 + 2 * i]) + (unsigned int)(-input[n - 1 - 2 * i]) + 32) >> 6);
    j2 = revtab[n8 + i];

    // Eliminate loop-carried dependency by ensuring independent ordering
    // Both operations can now be reordered freely due to decoupling

    // First butterfly update
    {
        int64_t accu_re = (int64_t)(-tcos[i]) * re1 - (int64_t)(tsin[i]) * im1;
        int64_t accu_im = (int64_t)(-tcos[i]) * im1 + (int64_t)(tsin[i]) * re1;
        x[j1].re = (int)((accu_re + 1073741824) >> 31);
        x[j1].im = (int)((accu_im + 1073741824) >> 31);
    }

    // Second butterfly update
    {
        int64_t accu_re = (int64_t)(-tcos[n8 + i]) * re2 - (int64_t)(tsin[n8 + i]) * im2;
        int64_t accu_im = (int64_t)(-tcos[n8 + i]) * im2 + (int64_t)(tsin[n8 + i]) * re2;
        x[j2].re = (int)((accu_re + 1073741824) >> 31);
        x[j2].im = (int)((accu_im + 1073741824) >> 31);
    }
}
}
