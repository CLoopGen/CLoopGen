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
    FFTSample *local_in1 = in1;
    FFTSample *local_in2 = in2;
    for (k = 0; k < n4; k++) {
        int idx = revtab[k];
        FFTSample cos_val = tcos[k];
        FFTSample sin_val = tsin[k];
        FFTSample temp_re = local_in2[0] * cos_val - local_in1[0] * sin_val;
        FFTSample temp_im = local_in2[0] * sin_val + local_in1[0] * cos_val;
        z[idx].re = temp_re;
        z[idx].im = temp_im;
        local_in1 += 2;
        local_in2 -= 2;
    }
    in1 = local_in1;
    in2 = local_in2;
}
