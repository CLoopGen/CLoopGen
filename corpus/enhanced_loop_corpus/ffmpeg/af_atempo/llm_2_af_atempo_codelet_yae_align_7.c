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
    // Variant 1: Strided memory access with increased stride (access every 2nd element)
    // Adjust loop bounds to prevent out-of-bounds access
    int stride = 2;
    int step;
    for (i = i0, step = 0; i < i1; i += stride, xcorr += stride, step++) {
        FFTSample metric = *xcorr;
        FFTSample drifti = (FFTSample)(drift + i);
        metric *= drifti * (FFTSample)(i - i0) * (FFTSample)(i1 - i);
        if (metric > best_metric) {
            best_metric = metric;
            best_offset = i - window / 2;
        }
    }
}
