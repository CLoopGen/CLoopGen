#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef int32_t FFTSample;
typedef int FFTDouble;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTSample *input;
int i;
int j;
int n;
int n8;
int n4;
int n2;
int n3;
FFTDouble re;
FFTDouble im;
uint16_t *revtab;
FFTSample *tcos;
FFTSample *tsin;
FFTComplex *x;

void init_vars() {
    n = 1 << 20; // 1M FFT size -> input array of size n
    n8 = n / 8;
    n4 = n / 4;
    n2 = n / 2;
    n3 = 3 * n / 4;

    // Allocate input: size n
    input = (FFTSample*)aligned_alloc(32, n * sizeof(FFTSample));
    
    // Allocate revtab: size n/8 + n/8 = n/4
    revtab = (uint16_t*)aligned_alloc(32, n4 * sizeof(uint16_t));
    
    // Allocate tcos and tsin: size n/8 + n/8 = n/4
    tcos = (FFTSample*)aligned_alloc(32, n4 * sizeof(FFTSample));
    tsin = (FFTSample*)aligned_alloc(32, n4 * sizeof(FFTSample));
    
    // Allocate x: size at least n/4 to cover all revtab indices
    x = (FFTComplex*)aligned_alloc(32, n4 * sizeof(FFTComplex));

    // Initialize input with random data
    srand((unsigned int)time(NULL));
    for (int idx = 0; idx < n; idx++) {
        input[idx] = (FFTSample)(rand() % 65536 - 32768);
    }

    // Initialize revtab with valid reverse indices in [0, n/4)
    for (int idx = 0; idx < n4; idx++) {
        uint16_t reversed = 0;
        int log_n4 = 0;
        int temp = n4;
        while (temp >>= 1) log_n4++;
        for (int bit = 0; bit < log_n4; bit++) {
            if (idx & (1 << bit)) {
                reversed |= (1 << (log_n4 - 1 - bit));
            }
        }
        revtab[idx] = reversed % n4;
    }

    // Initialize tcos and tsin with non-zero values
    for (int idx = 0; idx < n4; idx++) {
        tcos[idx] = (FFTSample)(rand() % 65536 - 32768);
        tsin[idx] = (FFTSample)(rand() % 65536 - 32768);
    }

    // Initialize x to zero
    for (int idx = 0; idx < n4; idx++) {
        x[idx].re = 0;
        x[idx].im = 0;
    }

    // Initialize loop counters
    i = 0;
    j = 0;
    re = 0;
    im = 0;
}