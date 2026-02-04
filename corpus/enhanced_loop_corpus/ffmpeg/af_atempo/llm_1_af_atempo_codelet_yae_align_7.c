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
    for (i = i0; i < i1; i++) {
        FFTSample metric = xcorr[i - i0];
        for (int unroll = 0; unroll < 1; unroll++) {
            FFTSample drifti = (FFTSample)(drift + i);
            metric *= drifti * (FFTSample)(i - i0) * (FFTSample)(i1 - i);
            if (metric > best_metric) {
                best_metric = metric;
                best_offset = i - window / 2;
            }
        }
    }
    xcorr += (i1 - i0);
}
