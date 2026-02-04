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
for (y = start; y < end; y++) {
    int yn = y * n;
    int *indices = (int*)alloca(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        indices[i] = yn + ((i * 7) % n);  // Strided indirect access pattern using modulo
    }
    for (x = 0; x < n; x++) {
        int idx = indices[x];
        FFTSample re, im, ire, iim;
        re = input[idx].re;
        im = input[idx].im;
        ire = filter[idx].re + noise;
        iim = filter[idx].im;
        input[idx].re = ire * re - iim * im;
        input[idx].im = iim * re + ire * im;
    }
}
}
