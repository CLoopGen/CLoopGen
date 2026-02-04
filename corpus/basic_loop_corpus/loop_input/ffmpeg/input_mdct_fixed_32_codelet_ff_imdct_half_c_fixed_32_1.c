#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef int32_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

int k;
int n8;
FFTSample *tcos;
FFTSample *tsin;
FFTComplex *z;

static const size_t DATA_SIZE_MB = 64;
static const size_t TOTAL_SIZE = DATA_SIZE_MB * (1 << 20); // 64MB total buffer space

void init_vars() {
    // Estimate required memory layout to avoid out-of-bounds access in loop
    // Loop runs for k in [0, n8), and accesses:
    //   z[n8 - k - 1] -> max index: n8 - 1 (when k=0), min: 0 (when k=n8-1)
    //   z[n8 + k]     -> max index: n8 + n8 - 1 = 2*n8 - 1
    // So z must have at least 2*n8 elements.
    //
    // Similarly, tcos and tsin are accessed at indices [n8 - k - 1] and [n8 + k],
    // so they need at least 2*n8 elements as well.

    // Choose n8 such that total data size is about 64MB
    // Each of z, tcos, tsin has 2*n8 elements
    // z: 2*n8 * sizeof(FFTComplex) = 2*n8 * 8 bytes
    // tcos/tsin: 2 * (2*n8 * 4) = 16*n8 bytes
    // Total ~ 32*n8 bytes => set 32*n8 ≈ 64MB => n8 ≈ 2^20 = 1<<20

    n8 = 1 << 19;  // So 2*n8 = 2^20 = 1M elements per array

    size_t z_size = 2 * n8;
    size_t t_size = 2 * n8;

    // Allocate z, tcos, tsin
    z = aligned_alloc(32, z_size * sizeof(FFTComplex));
    tcos = aligned_alloc(32, t_size * sizeof(FFTSample));
    tsin = aligned_alloc(32, t_size * sizeof(FFTSample));

    if (!z || !tcos || !tsin) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize tcos and tsin with non-zero values
    for (size_t i = 0; i < t_size; i++) {
        tcos[i] = (FFTSample)(i & 0xFFFFF);
        tsin[i] = (FFTSample)((i ^ 0xAAAAAAAA) & 0xFFFFF);
    }

    // Initialize z with sample data
    for (size_t i = 0; i < z_size; i++) {
        z[i].re = (FFTSample)(i * 7);
        z[i].im = (FFTSample)(i * 13);
    }
}