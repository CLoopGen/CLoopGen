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
E KP707106781;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~8MB for cr and ci each (double), ~4.8MB for W, total ~25.6MB
    const INT vector_length = 8;

    cr = (R*)aligned_alloc(64, N * sizeof(R));
    ci = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, N * 6 * sizeof(R));
    rs = (INT*)aligned_alloc(64, vector_length * sizeof(INT));

    for (size_t i = 0; i < N; ++i) {
        cr[i] = (R)(drand48() * 2.0 - 1.0);
        ci[i] = (R)(drand48() * 2.0 - 1.0);
    }
    for (size_t i = 0; i < N * 6; ++i) {
        W[i] = (R)(drand48() * 2.0 - 1.0);
    }

    for (INT i = 0; i < vector_length; ++i) {
        rs[i] = (i * 31) % N; // pseudo-random strides within bounds
    }

    KP707106781 = (E)(1.0 / sqrt(2.0)); // standard constant

    mb = 1;
    me = N;
    ms = 1;

    // Ensure loop bounds are safe: m from mb to me-1, W accessed at offset (mb-1)*6 and up
    // W has 6 elements per iteration, so we need at least (me - mb + 1) * 6 starting from (mb-1)*6
    // Our allocation ensures enough space.
}