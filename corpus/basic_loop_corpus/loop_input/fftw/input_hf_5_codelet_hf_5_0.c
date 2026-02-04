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
E KP250000000;
E KP559016994;
E KP587785252;
E KP951056516;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~1M elements, sufficient for ~0.01s runtime

    cr = (R*)aligned_alloc(32, N * sizeof(R));
    ci = (R*)aligned_alloc(32, N * sizeof(R));
    W = (R*)aligned_alloc(32, 8 * N * sizeof(R));
    rs = (INT*)aligned_alloc(32, 5 * sizeof(INT));

    // Initialize constants
    KP250000000 = 0.25;
    KP559016994 = 0.559016994;
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;

    // Set stride values to valid small offsets
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;
    rs[4] = 4;

    // Initialize data arrays with non-zero values for meaningful computation
    for (size_t i = 0; i < N; ++i) {
        cr[i] = (R)(i + 1);
        ci[i] = (R)(-(ptrdiff_t)i);
    }
    for (size_t i = 0; i < 8 * N; ++i) {
        W[i] = (R)(i % 8) * 0.1 + 1.0;
    }

    // Configure loop bounds to stay within allocated memory
    mb = 1;
    me = N - 4; // Ensure rs[4] access stays in bounds
    ms = 1;     // Stride step
}