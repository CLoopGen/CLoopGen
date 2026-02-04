#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

int window = 512;
int drift = 10;
int best_offset = 0;
FFTSample best_metric = -1e30f;
FFTSample *xcorr = NULL;
int i0 = 0;
int i1 = 1 << 20; // ~1M elements, sufficient for ~0.01 sec runtime
int i = 0;

void init_vars() {
    xcorr = (FFTSample*)aligned_alloc(32, sizeof(FFTSample) * (i1 - i0));
    if (!xcorr) {
        exit(1);
    }
    for (int j = 0; j < i1 - i0; j++) {
        xcorr[j] = (FFTSample)(0.1f + (j % 100) * 0.01f);
    }
    best_metric = -1e30f;
    best_offset = 0;
}