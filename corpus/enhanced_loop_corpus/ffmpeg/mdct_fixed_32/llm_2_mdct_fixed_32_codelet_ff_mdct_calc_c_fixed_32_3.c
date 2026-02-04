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
        int idx1 = 2 * i + n3;
        int idx2 = n3 - 1 - 2 * i;
        int idx3 = n4 + 2 * i;
        int idx4 = n4 - 1 - 2 * i;
        re = ((int)((-input[idx1]) + (unsigned int)(-input[idx2]) + 32) >> 6);
        im = ((int)((-input[idx3]) + (unsigned int)(+input[idx4]) + 32) >> 6);
        j = revtab[i];
        int64_t accu1 = (int64_t)(-tcos[i]) * re - (int64_t)(tsin[i]) * im;
        x[j].re = (int)((accu1 + 1073741824) >> 31);
        int64_t accu2 = (int64_t)(-tcos[i]) * im + (int64_t)(tsin[i]) * re;
        x[j].im = (int)((accu2 + 1073741824) >> 31);

        int idx5 = 2 * i;
        int idx6 = n2 - 1 - 2 * i;
        int idx7 = n2 + 2 * i;
        int idx8 = n - 1 - 2 * i;
        re = ((int)(input[idx5] + (unsigned int)(-input[idx6]) + 32) >> 6);
        im = ((int)((-input[idx7]) + (unsigned int)(-input[idx8]) + 32) >> 6);
        j = revtab[n8 + i];
        accu1 = (int64_t)(-tcos[n8 + i]) * re - (int64_t)(tsin[n8 + i]) * im;
        x[j].re = (int)((accu1 + 1073741824) >> 31);
        accu2 = (int64_t)(-tcos[n8 + i]) * im + (int64_t)(tsin[n8 + i]) * re;
        x[j].im = (int)((accu2 + 1073741824) >> 31);
    }
}
