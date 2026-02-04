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
R *ro;
R *io;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
E KP831469612 = 0.8314696123025452;
E KP555570233 = 0.5555702330196022;
E KP195090322 = 0.19509032201612825;
E KP980785280 = 0.9807852804032304;
E KP923879532 = 0.9238795325112867;
E KP382683432 = 0.3826834323650898;
E KP707106781 = 0.7071067811865476;
INT i;

void init_vars() {
    const INT N = 32;
    const INT data_size = 1 << 20; // ~1MB per array
    const INT vector_count = data_size / (N * sizeof(R));
    v = (vector_count > 0) ? vector_count : 1;

    ri = (R*)aligned_alloc(64, v * N * sizeof(R));
    ii = (R*)aligned_alloc(64, v * N * sizeof(R));
    ro = (R*)aligned_alloc(64, v * N * sizeof(R));
    io = (R*)aligned_alloc(64, v * N * sizeof(R));
    is = (INT*)aligned_alloc(64, N * sizeof(INT));
    os = (INT*)aligned_alloc(64, N * sizeof(INT));

    ivs = N;
    ovs = N;

    for (INT idx = 0; idx < N; ++idx) {
        is[idx] = idx;
        os[idx] = idx;
    }

    for (INT vec = 0; vec < v * N; ++vec) {
        ri[vec] = (R)(rand() % 1000) / 1000.0;
        ii[vec] = (R)(rand() % 1000) / 1000.0;
        ro[vec] = 0.0;
        io[vec] = 0.0;
    }
}