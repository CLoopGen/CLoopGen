#include <stdlib.h>
#include <stddef.h>

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

E KP654860733 = 0.654860733;
E KP142314838 = 0.142314838;
E KP959492973 = 0.959492973;
E KP415415013 = 0.415415013;
E KP841253532 = 0.841253532;
E KP989821441 = 0.989821441;
E KP909631995 = 0.909631995;
E KP281732556 = 0.281732556;
E KP540640817 = 0.540640817;
E KP755749574 = 0.755749574;

INT i;

void init_vars() {
    const size_t N = 131072;  // ~1MB per array (double: 8 bytes)
    v = N;
    ivs = 1;
    ovs = 1;

    ri = (R*)aligned_alloc(64, N * sizeof(R));
    ii = (R*)aligned_alloc(64, N * sizeof(R));
    ro = (R*)aligned_alloc(64, N * sizeof(R));
    io = (R*)aligned_alloc(64, N * sizeof(R));
    is = (stride)aligned_alloc(64, 11 * sizeof(INT));
    os = (stride)aligned_alloc(64, 11 * sizeof(INT));

    for (size_t j = 0; j < N; ++j) {
        ri[j] = (R)(j % 1000) * 0.01;
        ii[j] = (R)((j + 100) % 900) * 0.01;
        ro[j] = 0.0;
        io[j] = 0.0;
    }

    for (int j = 0; j < 11; ++j) {
        is[j] = j;
        os[j] = j;
    }
}