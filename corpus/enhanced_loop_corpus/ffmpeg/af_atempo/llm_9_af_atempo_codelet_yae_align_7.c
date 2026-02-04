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
int step = 2; // Increase loop stride to reduce trip count by ~50%
for (i = i0; i < i1; i += step, xcorr += step) {
    FFTSample metric = *xcorr;
    FFTSample drifti = (FFTSample)(drift + i);
    metric *= drifti * (FFTSample)(i - i0) * (FFTSample)(i1 - i);
    if (metric > best_metric) {
        best_metric = metric;
        best_offset = i - window / 2;
    }
    // Ensure xcorr pointer stays valid if step == 2
    if (i + 1 < i1) {
        FFTSample metric_next = *(xcorr + 1);
        FFTSample drifti_next = (FFTSample)(drift + i + 1);
        metric_next *= drifti_next * (FFTSample)(i + 1 - i0) * (FFTSample)(i1 - (i + 1));
        if (metric_next > best_metric) {
            best_metric = metric_next;
            best_offset = (i + 1) - window / 2;
        }
    }
}
}
