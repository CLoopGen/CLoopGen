#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2
E KP500000000 = 0.5;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~16 million elements, adjust for ~0.01s runtime

    cr = (R*)aligned_alloc(64, sizeof(R) * N);
    ci = (R*)aligned_alloc(64, sizeof(R) * N);
    W = (R*)aligned_alloc(64, sizeof(R) * (N * 4)); // W is accessed with +4 stride per loop

    rs = (stride)aligned_alloc(64, sizeof(INT) * 3);
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;

    // Initialize data arrays to non-zero values for realism
    for (size_t i = 0; i < N; ++i) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }
    for (size_t i = 0; i < N * 4; ++i) {
        W[i] = sin(i * 0.001);
    }

    // Set loop bounds to ensure safe access within allocated ranges
    mb = 1;
    me = N - 2;  // Ensure m+1 and rs indexing stays in bounds
    ms = 1;      // Stride increment for cr and ci
}