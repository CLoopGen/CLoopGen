#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern int k;
extern int n8;
extern  FFTSample *tcos;
extern  FFTSample *tsin;
extern FFTComplex *z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < n8; k++) {
        FFTSample r0, i0, r1, i1;
        int idx1 = n8 - k - 1;
        int idx2 = n8 + k;

        int64_t accu1 = (int64_t)(tsin[idx1]) * (z[idx1].im);
        accu1 -= (int64_t)(tcos[idx1]) * (z[idx1].re);
        r0 = (int)((accu1 + 1073741824) >> 31);

        int64_t accu2 = (int64_t)(tsin[idx1]) * (z[idx1].re);
        accu2 += (int64_t)(tcos[idx1]) * (z[idx1].im);
        i1 = (int)((accu2 + 1073741824) >> 31);

        int64_t accu3 = (int64_t)(tsin[idx2]) * (z[idx2].im);
        accu3 -= (int64_t)(tcos[idx2]) * (z[idx2].re);
        r1 = (int)((accu3 + 1073741824) >> 31);

        int64_t accu4 = (int64_t)(tsin[idx2]) * (z[idx2].re);
        accu4 += (int64_t)(tcos[idx2]) * (z[idx2].im);
        i0 = (int)((accu4 + 1073741824) >> 31);

        z[idx1].re = r0;
        z[idx1].im = i0;
        z[idx2].re = r1;
        z[idx2].im = i1;
    }
}
