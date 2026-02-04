#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  int window;
extern  int drift;
extern int best_offset;
extern FFTSample best_metric;
extern FFTSample *xcorr;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using array indexing instead of pointer arithmetic
    // Ensures predictable cache behavior and eliminates pointer mutation
    ptrdiff_t offset = 0;
    for (i = i0; i < i1; i++, offset++) {
        FFTSample metric = xcorr[offset];  // Base pointer + consecutive offset
        FFTSample drifti = (FFTSample)(drift + i);
        metric *= drifti * (FFTSample)(i - i0) * (FFTSample)(i1 - i);
        if (metric > best_metric) {
            best_metric = metric;
            best_offset = i - window / 2;
        }
    }
}
