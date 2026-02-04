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
    // Strided memory access pattern with precomputed index array (simulated via arithmetic)
    // Access elements in a non-sequential, strided manner: process every 2nd butterfly pair
    // This variant assumes n8 is even and uses a stride of 2 for k

    for (k = 0; k < n8; k += 2) {
        // Handle two iterations at once using strided access
        if (k + 1 >= n8) break;

        FFTSample r0_0, i0_0, r1_0, i1_0;
        FFTSample r0_1, i0_1, r1_1, i1_1;

        int idx1_0 = n8 - k     - 1;
        int idx2_0 = n8 + k;
        int idx1_1 = n8 - k - 1 - 1;
        int idx2_1 = n8 + k + 1;

        // First pair
        int64_t accu = (int64_t)(tsin[idx1_0]) * (z[idx1_0].im);
        accu -= (int64_t)(tcos[idx1_0]) * (z[idx1_0].re);
        r0_0 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx1_0]) * (z[idx1_0].re);
        accu += (int64_t)(tcos[idx1_0]) * (z[idx1_0].im);
        i1_0 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx2_0]) * (z[idx2_0].im);
        accu -= (int64_t)(tcos[idx2_0]) * (z[idx2_0].re);
        r1_0 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx2_0]) * (z[idx2_0].re);
        accu += (int64_t)(tcos[idx2_0]) * (z[idx2_0].im);
        i0_0 = (int)((accu + 1073741824) >> 31);

        // Second pair
        accu = (int64_t)(tsin[idx1_1]) * (z[idx1_1].im);
        accu -= (int64_t)(tcos[idx1_1]) * (z[idx1_1].re);
        r0_1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx1_1]) * (z[idx1_1].re);
        accu += (int64_t)(tcos[idx1_1]) * (z[idx1_1].im);
        i1_1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx2_1]) * (z[idx2_1].im);
        accu -= (int64_t)(tcos[idx2_1]) * (z[idx2_1].re);
        r1_1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx2_1]) * (z[idx2_1].re);
        accu += (int64_t)(tcos[idx2_1]) * (z[idx2_1].im);
        i0_1 = (int)((accu + 1073741824) >> 31);

        // Store results
        z[idx1_0].re = r0_0;
        z[idx1_0].im = i0_0;
        z[idx2_0].re = r1_0;
        z[idx2_0].im = i1_0;

        z[idx1_1].re = r0_1;
        z[idx1_1].im = i0_1;
        z[idx2_1].re = r1_1;
        z[idx2_1].im = i1_1;
    }

    // Handle leftover odd iteration
    if (k < n8) {
        int idx1 = n8 - k - 1;
        int idx2 = n8 + k;

        int64_t accu = (int64_t)(tsin[idx1]) * (z[idx1].im);
        accu -= (int64_t)(tcos[idx1]) * (z[idx1].re);
        FFTSample r0 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx1]) * (z[idx1].re);
        accu += (int64_t)(tcos[idx1]) * (z[idx1].im);
        FFTSample i1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx2]) * (z[idx2].im);
        accu -= (int64_t)(tcos[idx2]) * (z[idx2].re);
        FFTSample r1 = (int)((accu + 1073741824) >> 31);

        accu = (int64_t)(tsin[idx2]) * (z[idx2].re);
        accu += (int64_t)(tcos[idx2]) * (z[idx2].im);
        FFTSample i0 = (int)((accu + 1073741824) >> 31);

        z[idx1].re = r0;
        z[idx1].im = i0;
        z[idx2].re = r1;
        z[idx2].im = i1;
    }
}
