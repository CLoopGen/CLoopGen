#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTComplex *h;
int L;
int M;

void init_vars() {
    L = 1 << 20; // 1M elements, roughly 8MB of data (each complex number is 8 bytes)
    M = L / 2;
    
    h = (FFTComplex*)calloc(L, sizeof(FFTComplex));
    if (!h) {
        exit(1);
    }
    
    // Initialize the first M elements to avoid undefined behavior if accessed
    for (int i = 0; i < M; i++) {
        h[i].re = 0.0f;
        h[i].im = 0.0f;
    }
}