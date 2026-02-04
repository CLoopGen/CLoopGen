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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced outer loop trip count
    int y_step = 2; // Process two rows at once, reducing trip count
    for (y = 0; y < ih; y += y_step) {
        FFTSample scale_re = 1.0f / (y + 1);
        for (x = 0; x < n; x++) {
            int idx_base = y * n + x;
            int idx_src = ih * n + x;
            // Additional arithmetic: scaled assignment and cross-coupling
            fft_hdata[idx_base].re = fft_hdata[idx_src].re * scale_re;
            fft_hdata[idx_base].im = 0;
            // Introduce dependency across real/imaginary parts
            if (x > 0) {
                fft_hdata[idx_base].re += fft_hdata[idx_base - 1].im * 0.5f;
            }
            // Duplicate operation for second row if within bounds
            if (y + 1 < ih) {
                int idx_next = (y + 1) * n + x;
                fft_hdata[idx_next].re = fft_hdata[idx_src].re * (scale_re * 0.9f);
                fft_hdata[idx_next].im = 0;
            }
        }
    }
}
