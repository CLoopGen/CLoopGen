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
for (i = 0; i < n8; i += 2) {
    if (i + 1 < n8) {
        // First element
        re = ((int)((-input[2 * i + n3]) + (unsigned int)(-input[n3 - 1 - 2 * i]) + 32) >> 6);
        im = ((int)((-input[n4 + 2 * i]) + (unsigned int)(+input[n4 - 1 - 2 * i]) + 32) >> 6);
        j = revtab[i];
        int64_t accu1 = (int64_t)(-tcos[i]) * re - (int64_t)(tsin[i]) * im;
        x[j].re = (int)((accu1 + 1073741824) >> 31);
        int64_t accu2 = (int64_t)(-tcos[i]) * im + (int64_t)(tsin[i]) * re;
        x[j].im = (int)((accu2 + 1073741824) >> 31);

        // Second element
        re = ((int)((-input[2*(i+1) + n3]) + (unsigned int)(-input[n3 - 1 - 2*(i+1)]) + 32) >> 6);
        im = ((int)((-input[n4 + 2*(i+1)]) + (unsigned int)(+input[n4 - 1 - 2*(i+1)]) + 32) >> 6);
        j = revtab[i+1];
        accu1 = (int64_t)(-tcos[i+1]) * re - (int64_t)(tsin[i+1]) * im;
        x[j].re = (int)((accu1 + 1073741824) >> 31);
        accu2 = (int64_t)(-tcos[i+1]) * im + (int64_t)(tsin[i+1]) * re;
        x[j].im = (int)((accu2 + 1073741824) >> 31);
    } else {
        // Handle leftover when n8 is odd
        re = ((int)((-input[2 * i + n3]) + (unsigned int)(-input[n3 - 1 - 2 * i]) + 32) >> 6);
        im = ((int)((-input[n4 + 2 * i]) + (unsigned int)(+input[n4 - 1 - 2 * i]) + 32) >> 6);
        j = revtab[i];
        int64_t accu = (int64_t)(-tcos[i]) * re - (int64_t)(tsin[i]) * im;
        x[j].re = (int)((accu + 1073741824) >> 31);
        accu = (int64_t)(-tcos[i]) * im + (int64_t)(tsin[i]) * re;
        x[j].im = (int)((accu + 1073741824) >> 31);
    }

    // Second block: process second half with stride
    re = ((int)((input[2 * i]) + (unsigned int)(-input[n2 - 1 - 2 * i]) + 32) >> 6);
    im = ((int)((-input[n2 + 2 * i]) + (unsigned int)(-input[n - 1 - 2 * i]) + 32) >> 6);
    j = revtab[n8 + i];
    int64_t accu1 = (int64_t)(-tcos[n8 + i]) * re - (int64_t)(tsin[n8 + i]) * im;
    x[j].re = (int)((accu1 + 1073741824) >> 31);
    int64_t accu2 = (int64_t)(-tcos[n8 + i]) * im + (int64_t)(tsin[n8 + i]) * re;
    x[j].im = (int)((accu2 + 1073741824) >> 31);

    if (i + 1 < n8) {
        re = ((int)((input[2*(i+1)]) + (unsigned int)(-input[n2 - 1 - 2*(i+1)]) + 32) >> 6);
        im = ((int)((-input[n2 + 2*(i+1)]) + (unsigned int)(-input[n - 1 - 2*(i+1)]) + 32) >> 6);
        j = revtab[n8 + i + 1];
        accu1 = (int64_t)(-tcos[n8 + i + 1]) * re - (int64_t)(tsin[n8 + i + 1]) * im;
        x[j].re = (int)((accu1 + 1073741824) >> 31);
        accu2 = (int64_t)(-tcos[n8 + i + 1]) * im + (int64_t)(tsin[n8 + i + 1]) * re;
        x[j].im = (int)((accu2 + 1073741824) >> 31);
    }
}
}
