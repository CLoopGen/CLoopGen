#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern int k;
extern int n4;
extern int j;
extern  uint16_t *revtab;
extern  FFTSample *tcos;
extern  FFTSample *tsin;
extern  FFTSample *in1;
extern  FFTSample *in2;
extern FFTComplex *z;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (k = 0; k < n4; k++) {
        j = revtab[k];
        FFTSample temp_re = in2[(n4 - 1 - k) * 2] * tcos[k] - in1[k * 2] * tsin[k];
        FFTSample temp_im = in2[(n4 - 1 - k) * 2] * tsin[k] + in1[k * 2] * tcos[k];
        z[j].re = temp_re;
        z[j].im = temp_im;
    }
    in1 += n4 * 2;
    in2 -= n4 * 2;
}
