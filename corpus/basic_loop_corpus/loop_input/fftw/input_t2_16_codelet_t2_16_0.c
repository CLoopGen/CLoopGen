#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

void init_vars() {
    const size_t N = (1 << 20); // ~16MB of complex data: 2^20 elements
    const size_t num_w = N * 8;  // W array has 8 values per iteration

    ri = (R*)aligned_alloc(32, sizeof(R) * N);
    ii = (R*)aligned_alloc(32, sizeof(R) * N);
    W = (R*)aligned_alloc(32, sizeof(R) * num_w);
    rs = (stride)aligned_alloc(32, sizeof(INT) * 16);

    // Initialize constants
    KP382683432 = sin(M_PI / 8.0);     // sin(22.5°)
    KP923879532 = cos(M_PI / 8.0);     // cos(22.5°)
    KP707106781 = sin(M_PI / 4.0);     // sin(45°) ≈ 0.7071

    // Initialize rs strides: assume 16-point FFT-like access pattern
    for (int i = 0; i < 16; ++i) {
        rs[i] = i;
    }

    // Set loop bounds
    mb = 0;
    me = N / 16;  // Each iteration processes 16 elements
    ms = 16;      // Stride step for ri and ii

    // Initialize input arrays with non-zero test values to avoid trivial optimization
    for (size_t i = 0; i < N; ++i) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
    }

    // Initialize W array with twiddle factors (8 per block)
    for (INT blk = 0; blk < me; ++blk) {
        R angle = 2.0 * M_PI * blk / me;
        W[blk*8 + 0] = cos(0 * angle);
        W[blk*8 + 1] = sin(0 * angle);
        W[blk*8 + 2] = cos(1 * angle);
        W[blk*8 + 3] = sin(1 * angle);
        W[blk*8 + 4] = cos(2 * angle);
        W[blk*8 + 5] = sin(2 * angle);
        W[blk*8 + 6] = cos(3 * angle);
        W[blk*8 + 7] = sin(3 * angle);
    }
}