#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *ri = NULL;
R *ii = NULL;
R *W = NULL;
stride rs = NULL;
INT mb = 0;
INT me = 0;
INT ms = 0;
E KP707106781 = 0.70710678118654758; // Approximation of 1/sqrt(2)
INT m = 0;

void init_vars() {
    const size_t N = 1 << 20;  // 1M elements for reasonable runtime (~tens of ms)

    mb = 0;
    me = N / 8;  // Each iteration accesses up to rs[7], so we need at least 8*me <= N
    ms = 8;      // Stride step in ri and ii arrays per iteration
    KP707106781 = 0.70710678118654758;

    // Allocate aligned memory to avoid issues and ensure proper access
    ri = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), N * sizeof(R));  // W is accessed up to offset 13 + 14*(me-1)

    // Allocate and initialize stride array rs of length at least 8
    rs = (INT*)aligned_alloc(sizeof(INT), 8 * sizeof(INT));
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;
    rs[4] = 4;
    rs[5] = 5;
    rs[6] = 6;
    rs[7] = 7;

    // Initialize input arrays to prevent NaN/undefined behavior
    for (size_t i = 0; i < N; ++i) {
        ri[i] = (R)(i & 1 ? 1.0 : -1.0);
        ii[i] = (R)((i & 2) ? 0.5 : -0.5);
        W[i] = (R)(1.0 / (1.0 + (i % 64)));  // Smooth decay pattern
    }
}