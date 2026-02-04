#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *fft_hdata;
extern int n;
extern  int ih;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase trip count by unrolling the outer loop and adjusting inner bounds
    int total_iterations = ih * n;
    int idx;
    for (idx = 0; idx < total_iterations; idx++) {
        int y = n - ih + (idx / n);
        int x = idx % n;
        int src_x = (n - ih - 1) * n + x;
        int dst_idx = y * n + x;

        // Perform copy with redundant zero assignment merged into single operation
        fft_hdata[dst_idx].re = fft_hdata[src_x].re;
        fft_hdata[dst_idx].im = 0;

        // Extra arithmetic: introduce lightweight scaling based on index
        if ((idx % (n + 1)) == 0) {
            fft_hdata[dst_idx].re *= 1.0f + 1e-6f;
        }
    }
}
