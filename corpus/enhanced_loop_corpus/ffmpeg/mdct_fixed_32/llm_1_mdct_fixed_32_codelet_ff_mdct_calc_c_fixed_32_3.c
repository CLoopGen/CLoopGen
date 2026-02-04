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



void loop() {
    for (i = 0; i < n8; i++) {
        FFTSample re_part, im_part;
        int j_idx;

        for (int phase = 0; phase < 2; phase++) {
            if (phase == 0) {
                re_part = ((int)((-input[2 * i + n3]) + (unsigned int)(-input[n3 - 1 - 2 * i]) + 32) >> 6);
                im_part = ((int)((-input[n4 + 2 * i]) + (unsigned int)(+input[n4 - 1 - 2 * i]) + 32) >> 6);
                j_idx = revtab[i];
                int64_t accu_re = (int64_t)(-tcos[i]) * re_part - (int64_t)(tsin[i]) * im_part;
                int64_t accu_im = (int64_t)(-tcos[i]) * im_part + (int64_t)(tsin[i]) * re_part;
                x[j_idx].re = (int)((accu_re + 1073741824) >> 31);
                x[j_idx].im = (int)((accu_im + 1073741824) >> 31);
            } else {
                re_part = ((int)((input[2 * i]) + (unsigned int)(-input[n2 - 1 - 2 * i]) + 32) >> 6);
                im_part = ((int)((-input[n2 + 2 * i]) + (unsigned int)(-input[n - 1 - 2 * i]) + 32) >> 6);
                j_idx = revtab[n8 + i];
                int64_t accu_re = (int64_t)(-tcos[n8 + i]) * re_part - (int64_t)(tsin[n8 + i]) * im_part;
                int64_t accu_im = (int64_t)(-tcos[n8 + i]) * im_part + (int64_t)(tsin[n8 + i]) * re_part;
                x[j_idx].re = (int)((accu_re + 1073741824) >> 31);
                x[j_idx].im = (int)((accu_im + 1073741824) >> 31);
            }
        }
    }
}
