#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
INT m = 0;

void init_vars() {
    const size_t N = (1 << 20); // ~16.8 million complex elements -> ~256MB total data

    ri = (R*)aligned_alloc(32, sizeof(R) * N * 4);
    ii = (R*)aligned_alloc(32, sizeof(R) * N * 4);
    W = (R*)aligned_alloc(32, sizeof(R) * 6 * N);

    rs = (stride)aligned_alloc(32, sizeof(INT) * 4);
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    for (size_t i = 0; i < N * 4; ++i) {
        ri[i] = (R)(rand() % 1000) / 100.0;
        ii[i] = (R)(rand() % 1000) / 100.0;
    }

    for (size_t i = 0; i < N * 6; ++i) {
        W[i] = (R)(rand() % 1000) / 100.0;
    }

    mb = 0;
    me = N;
    ms = 4;
}