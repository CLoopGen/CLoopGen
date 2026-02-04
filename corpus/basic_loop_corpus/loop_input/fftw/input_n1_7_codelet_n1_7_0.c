#include <stdio.h>
#include <inttypes.h>
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
E KP222520933 = 0.222520933;
E KP900968867 = 0.900968867;
E KP623489801 = 0.623489801;
E KP433883739 = 0.433883739;
E KP781831482 = 0.781831482;
E KP974927912 = 0.974927912;
INT i;

void init_vars() {
    const INT N = 65536; // Size to achieve ~0.01 sec runtime

    v = N;
    ivs = 1;
    ovs = 1;

    ri = (R*)aligned_alloc(32, N * sizeof(R));
    ii = (R*)aligned_alloc(32, N * sizeof(R));
    ro = (R*)aligned_alloc(32, N * sizeof(R));
    io = (R*)aligned_alloc(32, N * sizeof(R));
    is = (stride)aligned_alloc(32, 7 * sizeof(INT));
    os = (stride)aligned_alloc(32, 7 * sizeof(INT));

    for (INT idx = 0; idx < N; ++idx) {
        ri[idx] = (R)(idx % 1234) * 0.01;
        ii[idx] = (R)(idx % 5678) * 0.01;
        ro[idx] = 0.0;
        io[idx] = 0.0;
    }

    is[0] = 0; is[1] = 1; is[2] = 2; is[3] = 3; is[4] = 4; is[5] = 5; is[6] = 6;
    os[0] = 0; os[1] = 1; os[2] = 2; os[3] = 3; os[4] = 4; os[5] = 5; os[6] = 6;
}