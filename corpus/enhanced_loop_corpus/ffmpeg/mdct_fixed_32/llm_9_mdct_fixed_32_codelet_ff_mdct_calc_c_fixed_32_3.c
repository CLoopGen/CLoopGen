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
for (i = 0; i < n8 / 2; i++) {
    int idx1 = 2 * i, idx2 = 2 * i + 1;

    // Process two iterations' worth of first block computations
    FFTSample in_n3_1 = input[idx1 + n3], in_n3_2 = input[idx2 + n3];
    FFTSample in_rev1_1 = input[n3 - 1 - idx1], in_rev1_2 = input[n3 - 1 - idx2];
    FFTSample in_n4_1 = input[n4 + idx1], in_n4_2 = input[n4 + idx2];
    FFTSample in_rev2_1 = input[n4 - 1 - idx1], in_rev2_2 = input[n4 - 1 - idx2];

    FFTDouble re1 = ((int)((-in_n3_1) + (unsigned int)(-in_rev1_1) + 32) >> 6);
    FFTDouble im1 = ((int)((-in_n4_1) + (unsigned int)(+in_rev2_1) + 32) >> 6);
    FFTDouble re2 = ((int)((-in_n3_2) + (unsigned int)(-in_rev1_2) + 32) >> 6);
    FFTDouble im2 = ((int)((-in_n4_2) + (unsigned int)(+in_rev2_2) + 32) >> 6);

    int j1 = revtab[idx1 / 2], j2 = revtab[idx2 / 2]; // assuming mapping holds

    int64_t accu_re1 = (int64_t)(-tcos[i*2]) * re1 - (int64_t)(tsin[i*2]) * im1;
    int64_t accu_im1 = (int64_t)(-tcos[i*2]) * im1 + (int64_t)(tsin[i*2]) * re1;
    x[j1].re = (int)((accu_re1 + 1073741824) >> 31);
    x[j1].im = (int)((accu_im1 + 1073741824) >> 31);

    int64_t accu_re2 = (int64_t)(-tcos[i*2+1]) * re2 - (int64_t)(tsin[i*2+1]) * im2;
    int64_t accu_im2 = (int64_t)(-tcos[i*2+1]) * im2 + (int64_t)(tsin[i*2+1]) * re2;
    x[j2].re = (int)((accu_re2 + 1073741824) >> 31);
    x[j2].im = (int)((accu_im2 + 1073741824) >> 31);

    // Second part: symmetric update for second butterfly
    FFTSample in_1 = input[idx1], in_2 = input[idx2];
    FFTSample in_n2m1_1 = input[n2 - 1 - idx1], in_n2m1_2 = input[n2 - 1 - idx2];
    FFTSample in_n2p_1 = input[n2 + idx1], in_n2p_2 = input[n2 + idx2];
    FFTSample in_nm1_1 = input[n - 1 - idx1], in_nm1_2 = input[n - 1 - idx2];

    re1 = ((int)(in_1 + (unsigned int)(-in_n2m1_1) + 32) >> 6);
    im1 = ((int)((-in_n2p_1) + (unsigned int)(-in_nm1_1) + 32) >> 6);
    re2 = ((int)(in_2 + (unsigned int)(-in_n2m1_2) + 32) >> 6);
    im2 = ((int)((-in_n2p_2) + (unsigned int)(-in_nm1_2) + 32) >> 6);

    j1 = revtab[n8 + i*2];
    j2 = revtab[n8 + i*2 + 1];

    accu_re1 = (int64_t)(-tcos[n8 + i*2]) * re1 - (int64_t)(tsin[n8 + i*2]) * im1;
    accu_im1 = (int64_t)(-tcos[n8 + i*2]) * im1 + (int64_t)(tsin[n8 + i*2]) * re1;
    x[j1].re = (int)((accu_re1 + 1073741824) >> 31);
    x[j1].im = (int)((accu_im1 + 1073741824) >> 31);

    accu_re2 = (int64_t)(-tcos[n8 + i*2 + 1]) * re2 - (int64_t)(tsin[n8 + i*2 + 1]) * im2;
    accu_im2 = (int64_t)(-tcos[n8 + i*2 + 1]) * im2 + (int64_t)(tsin[n8 + i*2 + 1]) * re2;
    x[j2].re = (int)((accu_re2 + 1073741824) >> 31);
    x[j2].im = (int)((accu_im2 + 1073741824) >> 31);
}
}
