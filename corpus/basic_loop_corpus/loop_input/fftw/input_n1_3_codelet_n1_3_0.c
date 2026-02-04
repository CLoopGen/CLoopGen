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
E KP500000000 = 0.5;
E KP866025403 = 0.866025403;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double precision), total ~40MB
    const INT stride_size = 3;

    ri = (R*)aligned_alloc(32, data_size * sizeof(R));
    ii = (R*)aligned_alloc(32, data_size * sizeof(R));
    ro = (R*)aligned_alloc(32, data_size * sizeof(R));
    io = (R*)aligned_alloc(32, data_size * sizeof(R));
    is = (stride)aligned_alloc(32, stride_size * sizeof(INT));
    os = (stride)aligned_alloc(32, stride_size * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        ri[idx] = (R)(rand() % 1000) / 100.0;
        ii[idx] = (R)(rand() % 1000) / 100.0;
        ro[idx] = 0.0;
        io[idx] = 0.0;
    }

    is[0] = 0; is[1] = 1; is[2] = 2;
    os[0] = 0; os[1] = 1; os[2] = 2;

    v = data_size / 3;  
    ivs = 3;
    ovs = 3;
}