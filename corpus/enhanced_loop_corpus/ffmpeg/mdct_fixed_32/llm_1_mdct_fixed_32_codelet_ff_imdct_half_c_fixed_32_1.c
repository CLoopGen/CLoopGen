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
for (int outer = 0; outer < n8; outer += 2) {
    for (int inner = 0; inner < 2 && (outer + inner) < n8; inner++) {
        k = outer + inner;
        FFTSample r0, i0, r1, i1;
        int64_t accu;

        accu = (int64_t)(tsin[n8 - k - 1]) * (z[n8 - k - 1].im);
        accu -= (int64_t)(tcos[n8 - k - 1]) * (z[n8 - k - 1].re);
        r0 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[n8 - k - 1]) * (z[n8 - k - 1].re);
        accu += (int64_t)(tcos[n8 - k - 1]) * (z[n8 - k - 1].im);
        i1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[n8 + k]) * (z[n8 + k].im);
        accu -= (int64_t)(tcos[n8 + k]) * (z[n8 + k].re);
        r1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[n8 + k]) * (z[n8 + k].re);
        accu += (int64_t)(tcos[n8 + k]) * (z[n8 + k].im);
        i0 = (int)((accu + 1073741824) >> 31);

        z[n8 - k - 1].re = r0;
        z[n8 - k - 1].im = i0;
        z[n8 + k].re = r1;
        z[n8 + k].im = i1;
    }
}
}
