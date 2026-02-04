#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *input;
extern FFTComplex *filter;
extern  float noise;
extern  int n;
extern int start;
extern int end;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = start; y < end; y += 2) { // Double outer loop step to reduce iterations but increase per-iteration work
    for (x = 0; x < n; x++) {
        int yn1 = y * n;
        int yn2 = (y + 1) * n;
        
        // Process two rows simultaneously to increase computational intensity
        if (y < end) {
            FFTSample re1 = input[yn1 + x].re;
            FFTSample im1 = input[yn1 + x].im;
            FFTSample ire1 = filter[yn1 + x].re + noise;
            FFTSample iim1 = filter[yn1 + x].im;
            input[yn1 + x].re = ire1 * re1 - iim1 * im1;
            input[yn1 + x].im = iim1 * re1 + ire1 * im1;
        }

        if (y + 1 < end) {
            FFTSample re2 = input[yn2 + x].re;
            FFTSample im2 = input[yn2 + x].im;
            FFTSample ire2 = filter[yn2 + x].re + noise;
            FFTSample iim2 = filter[yn2 + x].im;
            input[yn2 + x].re = ire2 * re2 - iim2 * im2;
            input[yn2 + x].im = iim2 * re2 + ire2 * im2;
        }
    }
}
}
