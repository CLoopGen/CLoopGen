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
        int stride = 2;
        int offset1 = n3;
        int offset2 = n4;
        int offset3 = n2;
        int offset4 = n;

        int pos1 = offset1 + stride * i;
        int neg1 = offset1 - 1 - stride * i;
        int pos2 = offset2 + stride * i;
        int neg2 = offset2 - 1 - stride * i;

        re = ((int)((-input[pos1]) + (unsigned int)(-input[neg1]) + 32) >> 6);
        im = ((int)((-input[pos2]) + (unsigned int)(+input[neg2]) + 32) >> 6);

        j = revtab[i];
        int64_t term1 = (int64_t)(-tcos[i]) * re;
        int64_t term2 = (int64_t)(-tsin[i]) * im;
        x[j].re = (int)(((term1 + term2 + 1073741824) >> 31));

        term1 = (int64_t)(-tcos[i]) * im;
        term2 = (int64_t)(tsin[i]) * re;
        x[j].im = (int)(((term1 + term2 + 1073741824) >> 31));

        int pos3 = stride * i;
        int neg3 = offset3 - 1 - stride * i;
        int pos4 = offset3 + stride * i;
        int neg4 = offset4 - 1 - stride * i;

        re = ((int)(input[pos3] + (unsigned int)(-input[neg3]) + 32) >> 6);
        im = ((int)((-input[pos4]) + (unsigned int)(-input[neg4]) + 32) >> 6);

        j = revtab[n8 + i];
        term1 = (int64_t)(-tcos[n8 + i]) * re;
        term2 = (int64_t)(-tsin[n8 + i]) * im;
        x[j].re = (int)(((term1 + term2 + 1073741824) >> 31));

        term1 = (int64_t)(-tcos[n8 + i]) * im;
        term2 = (int64_t)(tsin[n8 + i]) * re;
        x[j].im = (int)(((term1 + term2 + 1073741824) >> 31));
    }
}
