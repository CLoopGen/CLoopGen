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
int stride = 1;
for (k = 0; k < n8 / 2; k++) {
    FFTSample r0, i0, r1, i1;
    for (int s = 0; s < stride; s++) {
        int offset = s * (n8 / 4);
        int idx1 = n8 - k - 1 - offset;
        int idx2 = n8 + k + offset;

        if (idx1 >= 0 && idx2 < 2*n8) {
            int64_t accu = (int64_t)(tsin[idx1]) * z[idx1].im - (int64_t)(tcos[idx1]) * z[idx1].re;
            r0 = (int)((accu + 1073741824) >> 31);
            accu = (int64_t)(tsin[idx1]) * z[idx1].re + (int64_t)(tcos[idx1]) * z[idx1].im;
            i1 = (int)((accu + 1073741824) >> 31);

            accu = (int64_t)(tsin[idx2]) * z[idx2].im - (int64_t)(tcos[idx2]) * z[idx2].re;
            r1 = (int)((accu + 1073741824) >> 31);
            accu = (int64_t)(tsin[idx2]) * z[idx2].re + (int64_t)(tcos[idx2]) * z[idx2].im;
            i0 = (int)((accu + 1073741824) >> 31);

            z[idx1].re = r0;
            z[idx1].im = i1;
            z[idx2].re = r1;
            z[idx2].im = i0;
        }
    }
}
}
