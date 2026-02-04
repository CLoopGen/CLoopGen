#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int16_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

int i;
int n8;
FFTSample *tcos;
FFTSample *tsin;
FFTComplex *x;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // Aim for ~64MB of data for sufficient workload
    
    // Estimate approximate size per iteration: each x entry is 4 bytes (2x int16), tcos/tsin are 2 bytes each
    // Each loop iteration accesses two x elements and two tcos/tsin pairs
    // We'll set n8 so that the total memory used is around total_data_size
    size_t estimated_per_iter_bytes = 2 * (sizeof(FFTComplex) + 2 * sizeof(FFTSample));
    n8 = total_data_size / estimated_per_iter_bytes;
    if (n8 == 0) n8 = 1;
    
    // Ensure symmetry in indexing: we access x[n8 - i - 1] and x[n8 + i], so need space for [0..2*n8-1]
    size_t x_size = 2 * n8;
    x = (FFTComplex*)aligned_alloc(32, x_size * sizeof(FFTComplex));
    
    // tcos and tsin need to be at least n8*2 + n8 (for index up to n8 + n8 - 1 = 2*n8 - 1)
    size_t ts_size = 2 * n8;
    tcos = (FFTSample*)aligned_alloc(32, ts_size * sizeof(FFTSample));
    tsin = (FFTSample*)aligned_alloc(32, ts_size * sizeof(FFTSample));
    
    // Initialize with pseudo-random but deterministic data
    srand(0);
    for (size_t idx = 0; idx < x_size; idx++) {
        x[idx].re = (rand() % 65536) - 32768;
        x[idx].im = (rand() % 65536) - 32768;
    }
    for (size_t idx = 0; idx < ts_size; idx++) {
        tcos[idx] = (rand() % 65536) - 32768;
        tsin[idx] = (rand() % 65536) - 32768;
    }
}

// External symbols defined