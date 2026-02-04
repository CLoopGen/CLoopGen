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
    FFTSample r0 = 0, i0 = 0, r1 = 0, i1 = 0;
    int64_t accu;

    if (k % 2 == 0) {
        accu = (int64_t)(tsin[n8 - k - 1]) * z[n8 - k - 1].im;
        accu -= (int64_t)(tcos[n8 - k - 1]) * z[n8 - k - 1].re;
        r0 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[n8 - k - 1]) * z[n8 - k - 1].re;
        accu += (int64_t)(tcos[n8 - k - 1]) * z[n8 - k - 1].im;
        i1 = (int)((accu + 1073741824) >> 31);

        z[n8 - k - 1].re = r0;
        z[n8 - k - 1].im = i1;
    } else {
        accu = (int64_t)(tsin[n8 + k]) * z[n8 + k].im;
        accu -= (int64_t)(tcos[n8 + k]) * z[n8 + k].re;
        r1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[n8 + k]) * z[n8 + k].re;
        accu += (int64_t)(tcos[n8 + k]) * z[n8 + k].im;
        i0 = (int)((accu + 1073741824) >> 31);

        z[n8 + k].re = r1;
        z[n8 + k].im = i0;
    }

    if (k % 2 == 1) {
        z[n8 - k - 1].re = r0;
        z[n8 - k - 1].im = i0;
    }
    if (k % 2 == 0 && k > 0) {
        z[n8 + k - 1].re = r1;
        z[n8 + k - 1].im = i1;
    }
}
}
