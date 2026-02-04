#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern  FFTComplex *xa;
extern  FFTComplex *xb;
extern  int window;
extern FFTComplex *xc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using index array (simulating gather pattern)
    // Assume an auxiliary index array exists; here we simulate it via pointer arithmetic offset
    // We access elements in a non-sequential order: reverse traversal
    FFTComplex *xa_base = xa;
    FFTComplex *xb_base = xb;
    FFTComplex *xc_base = xc;
    
    for (i = 1; i < window; i++) {
        int idx = window - 1 - i;  // Reverse index mapping
        xc_base[idx].re = (xa_base[idx].re * xb_base[idx].re + xa_base[idx].im * xb_base[idx].im);
        xc_base[idx].im = (xa_base[idx].im * xb_base[idx].re - xa_base[idx].re * xb_base[idx].im);
        i++;  // Increment inside to maintain loop progress (compensate for for-loop increment)
        if (i >= window) break;
    }
}
