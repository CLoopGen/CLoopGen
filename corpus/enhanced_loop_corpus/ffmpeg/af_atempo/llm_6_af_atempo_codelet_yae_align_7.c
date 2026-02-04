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
    FFTSample local_best_metric = best_metric;
    int local_best_offset = best_offset;
    for (i = i0; i < i1; i++, xcorr++) {
        FFTSample metric = *xcorr;
        FFTSample drifti = (FFTSample)(drift + i);
        metric *= drifti * (FFTSample)(i - i0) * (FFTSample)(i1 - i);
        if (metric > local_best_metric) {
            local_best_metric = metric;
            local_best_offset = i - window / 2;
        }
    }
    best_metric = local_best_metric;
    best_offset = local_best_offset;
}
