#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef R E;
typedef ptrdiff_t INT;
typedef INT *stride;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Global data arrays and variables
R *ri = NULL;
R *ii = NULL;
R *W = NULL;
stride rs = NULL;
INT mb = 0;
INT me = 16384; // number of iterations to ensure ~0.01s runtime
INT ms = 2;
INT m = 0;

E KP471396736 = 0.471396736;
E KP881921264 = 0.881921264;
E KP290284677 = 0.290284677;
E KP956940335 = 0.956940335;
E KP634393284 = 0.634393284;
E KP773010453 = 0.773010453;
E KP098017140 = 0.098017140;
E KP995184726 = 0.995184726;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP980785280 = 0.980785280;
E KP195090322 = 0.195090322;
E KP923879532 = 0.923879532;
E KP382683432 = 0.382683432;
E KP707106781 = 0.707106781;

void init_vars() {
    // Allocate large enough arrays for benchmarking (~1-2 seconds on typical CPU)
    const size_t N = 65536; // total complex elements (adjustable)
    const size_t W_size = (me - mb) * 10;
    
    ri = (R*)aligned_alloc(32, sizeof(R) * N);
    ii = (R*)aligned_alloc(32, sizeof(R) * N);
    W = (R*)aligned_alloc(32, sizeof(R) * W_size);
    rs = (INT*)aligned_alloc(32, sizeof(INT) * 64);

    // Initialize stride array with safe offsets
    for (int i = 0; i < 64; ++i) {
        rs[i] = i;
    }

    // Initialize W coefficients: simulate twiddle factors
    for (size_t i = 0; i < W_size; ++i) {
        W[i] = 0.1 + (i % 10) * 0.1;
    }

    // Initialize input data to avoid NaN/Inf propagation
    for (size_t i = 0; i < N; ++i) {
        ri[i] = 1.0 / (1.0 + i);
        ii[i] = -1.0 / (1.0 + i);
    }

    // Set loop bounds so that all memory accesses are in-bounds
    mb = 0;
    me = W_size / 10; // ensures W indexing up to [mb*10 + ... + 9]
    if (me > 16384) me = 16384; // cap for performance

    // Ensure rs indices used in loop (up to rs[63]) are valid
    for (int i = 0; i < 64; ++i) {
        rs[i] = (i * 1024) % (N / 2); // keep within half the buffer
    }
}