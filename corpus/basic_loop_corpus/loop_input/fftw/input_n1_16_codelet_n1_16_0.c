#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *ri;
R *ii;
R *ro;
R *io;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
E KP382683432;
E KP923879532;
E KP707106781;
INT i;

void init_vars() {
    const size_t N = 1 << 20; // ~8MB per array (double), total ~64MB
    v = N;
    ivs = 1;
    ovs = 1;

    KP382683432 = 0.382683432;
    KP923879532 = 0.923879532;
    KP707106781 = 0.707106781;

    ri = (R*)aligned_alloc(64, sizeof(R) * N * 16);
    ii = (R*)aligned_alloc(64, sizeof(R) * N * 16);
    ro = (R*)aligned_alloc(64, sizeof(R) * N * 16);
    io = (R*)aligned_alloc(64, sizeof(R) * N * 16);
    is = (stride)aligned_alloc(64, sizeof(INT) * 16);
    os = (stride)aligned_alloc(64, sizeof(INT) * 16);

    for (int idx = 0; idx < 16; ++idx) {
        is[idx] = idx;
        os[idx] = idx;
    }

    for (size_t j = 0; j < N * 16; ++j) {
        ri[j] = sin(j * 0.01);
        ii[j] = cos(j * 0.01);
        ro[j] = 0.0;
        io[j] = 0.0;
    }
}