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
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~16MB of data (each array is ~8MB for double)
    
    cr = (R*)aligned_alloc(64, sizeof(R) * N * 6);
    ci = (R*)aligned_alloc(64, sizeof(R) * N * 6);
    W = (R*)aligned_alloc(64, sizeof(R) * 10 * (N + 1));

    rs = (INT*)aligned_alloc(64, sizeof(INT) * 6);
    for (INT i = 0; i < 6; ++i) {
        rs[i] = i * (ptrdiff_t)N;
    }

    ms = 1;
    mb = 1;
    me = N;

    for (size_t i = 0; i < N * 6; ++i) {
        cr[i] = (R)(i & 255) / 255.0;
        ci[i] = (R)((i + 12) & 255) / 255.0;
    }

    for (size_t i = 0; i < 10 * (N + 1); ++i) {
        W[i] = (R)(i & 511) / 511.0;
    }
}