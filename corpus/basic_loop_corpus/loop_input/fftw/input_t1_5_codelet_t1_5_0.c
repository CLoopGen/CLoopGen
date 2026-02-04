#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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
E KP250000000;
E KP559016994;
E KP587785252;
E KP951056516;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~16MB of total data: suitable for ~0.01s runtime

    ri = (R*)aligned_alloc(32, N * sizeof(R));
    ii = (R*)aligned_alloc(32, N * sizeof(R));
    W = (R*)aligned_alloc(32, 8 * N * sizeof(R));

    rs = (INT*)aligned_alloc(32, 5 * sizeof(INT));
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;
    rs[4] = 4;

    mb = 0;
    me = N;
    ms = 1;

    KP250000000 = 0.25;
    KP559016994 = 0.559016994;
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;

    for (size_t i = 0; i < N; ++i) {
        ri[i] = (R)(i % 123);
        ii[i] = (R)(i % 456);
    }

    for (size_t i = 0; i < N * 8; ++i) {
        W[i] = (R)(i % 789) / 789.0;
    }
}