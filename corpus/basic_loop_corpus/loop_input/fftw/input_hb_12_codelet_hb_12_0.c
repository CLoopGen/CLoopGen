#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386;
INT m;

void init_vars() {
    const INT N = 131072; // Size of cr, ci arrays (ensures ~0.01s runtime)

    cr = (R*)aligned_alloc(64, N * sizeof(R));
    ci = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, 22 * sizeof(R));

    rs = (INT*)aligned_alloc(64, 12 * sizeof(INT));

    // Initialize stride array to valid indices within [0, N-1]
    for (INT i = 0; i < 12; i++) {
        rs[i] = i * (N / 12);
    }

    // Initialize W coefficients: 22 elements used as twiddle factors
    for (INT i = 0; i < 22; i++) {
        W[i] = 1.0 + ((i & 1) ? -0.1 : 0.1) * (i / 2); // Arbitrary stable values
    }

    // Initialize data arrays with non-zero values
    for (INT i = 0; i < N; i++) {
        cr[i] = (R)(i % 100) * 0.01;
        ci[i] = (R)((i + 49) % 100) * 0.01;
    }

    // Set loop bounds so that all memory accesses are in range
    mb = 1;
    me = 2;
    ms = 1;

    // Ensure that maximum index accessed is within bounds:
    // Maximum offset used: rs[11], and cr/ci accessed at offsets up to rs[11]
    // We set rs[11] to a safe value already via initialization above.
}