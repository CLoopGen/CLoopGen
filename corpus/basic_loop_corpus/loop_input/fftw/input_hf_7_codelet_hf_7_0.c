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
E KP222520933 = 0.222520933;
E KP900968867 = 0.900968867;
E KP623489801 = 0.623489801;
E KP433883739 = 0.433883739;
E KP974927912 = 0.974927912;
E KP781831482 = 0.781831482;
INT m;

static const INT N = 1 << 18; // ~256K elements, adjust for ~0.01s runtime
static const INT W_size = N * 12;
static const INT rs_size = N;

void init_vars() {
    cr = (R*)aligned_alloc(32, sizeof(R) * N);
    ci = (R*)aligned_alloc(32, sizeof(R) * N);
    W = (R*)aligned_alloc(32, sizeof(R) * W_size);
    rs = (INT*)aligned_alloc(32, sizeof(INT) * rs_size);

    for (INT i = 0; i < N; ++i) {
        cr[i] = (R)(i % 128) * 0.03;
        ci[i] = (R)((i + 19) % 128) * 0.03;
        rs[i] = (i % 64) + 1;
    }

    for (INT i = 0; i < W_size; ++i) {
        W[i] = (R)((i + 43) % 256) * 0.01;
    }

    mb = 1;
    me = N - 6;
    ms = 1;
}