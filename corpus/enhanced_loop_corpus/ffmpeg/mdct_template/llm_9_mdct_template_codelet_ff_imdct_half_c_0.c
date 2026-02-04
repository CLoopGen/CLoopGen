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



void loop(){
    for (k = 0; k < n4 / 2; k++) {
        j = revtab[k];
        FFTSample cos_val = tcos[k];
        FFTSample sin_val = tsin[k];
        FFTSample in1_val = *in1;
        FFTSample in2_val = *in2;

        z[j].re = in2_val * cos_val - in1_val * sin_val;
        z[j].im = in2_val * sin_val + in1_val * cos_val;

        int j2 = revtab[n4 - 1 - k];
        FFTSample cos_val2 = tcos[n4 - 1 - k];
        FFTSample sin_val2 = tsin[n4 - 1 - k];
        FFTSample in1_val2 = *(in1 + 2*(n4 - 1 - k));
        FFTSample in2_val2 = *(in2 - 2*(n4 - 1 - k));

        z[j2].re = in2_val2 * cos_val2 - in1_val2 * sin_val2;
        z[j2].im = in2_val2 * sin_val2 + in1_val2 * cos_val2;

        in1 += 2;
        in2 -= 2;
    }
}
