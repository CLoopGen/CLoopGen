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



void loop() {
    for (k = 0; k < n8; k++) {
        FFTSample r0, i0, r1, i1;
        int64_t accu_r0 = (int64_t)(tsin[n8 - k - 1]) * (z[n8 - k - 1].im) - 
                          (int64_t)(tcos[n8 - k - 1]) * (z[n8 - k - 1].re);
        int64_t accu_i1 = (int64_t)(tsin[n8 - k - 1]) * (z[n8 - k - 1].re) + 
                          (int64_t)(tcos[n8 - k - 1]) * (z[n8 - k - 1].im);

        r0 = (int)((accu_r0 + 1073741824) >> 31);
        i1 = (int)((accu_i1 + 1073741824) >> 31);

        int64_t accu_r1 = (int64_t)(tsin[n8 + k]) * (z[n8 + k].im) - 
                          (int64_t)(tcos[n8 + k]) * (z[n8 + k].re);
        int64_t accu_i0 = (int64_t)(tsin[n8 + k]) * (z[n8 + k].re) + 
                          (int64_t)(tcos[n8 + k]) * (z[n8 + k].im);

        r1 = (int)((accu_r1 + 1073741824) >> 31);
        i0 = (int)((accu_i0 + 1073741824) >> 31);

        z[n8 - k - 1].re = r0;
        z[n8 - k - 1].im = i0;
        z[n8 + k].re = r1;
        z[n8 + k].im = i1;
    }
}
