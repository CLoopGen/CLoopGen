#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
E KP500000000;
E KP866025403;
INT m;

void init_vars() {
    // Initialize constants
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;
    KP500000000 = 0.500000000;
    KP866025403 = 0.866025403;

    // Data size: aim for ~64MB of complex data (double precision, 16 bytes per element)
    const size_t N = 1 << 22; // ~4M elements -> 64MB total

    // Allocate arrays
    cr = (R*)aligned_alloc(64, sizeof(R) * N);
    ci = (R*)aligned_alloc(64, sizeof(R) * N);
    W = (R*)aligned_alloc(64, sizeof(R) * 28 * (N + 10)); // extra padding for offset access

    // Allocate and initialize stride array
    rs = (INT*)aligned_alloc(64, sizeof(INT) * 15); // indices up to rs[14] used

    // Set valid range for loop: ensure all indexed accesses are in bounds
    mb = 1;
    me = 1000; // limit iterations to avoid long runtime, adjust for ~0.01s
    ms = 1;

    // Ensure W + ((mb - 1) * 28) + 28*(me-mb) + 27 is within bounds
    if (me - mb > 1000) me = mb + 1000;

    // Initialize rs with non-unit strides but safe offsets
    for (int i = 0; i < 15; ++i) {
        rs[i] = (i + 1) * 2; // even strides to avoid overlap
    }

    // Initialize data arrays with non-zero values for meaningful computation
    for (size_t i = 0; i < N; ++i) {
        cr[i] = (R)(i % 128) * 0.01;
        ci[i] = (R)((i + 37) % 128) * 0.01;
    }
    for (size_t i = 0; i < 28 * (me - mb + 2); ++i) {
        W[i] = (R)(i % 28) * 0.01;
    }

    // Ensure m starts at mb
    m = mb;
}