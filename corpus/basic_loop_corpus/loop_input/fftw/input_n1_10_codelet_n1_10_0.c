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
E KP250000000 = 0.25;
E KP559016994 = 0.559016994;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
INT i;

void init_vars() {
    const INT N = 1048576; // ~8MB per array, total ~40MB, suitable for ~0.01s on modern CPUs
    v = N;
    ivs = 1;
    ovs = 1;

    ri = (R*)aligned_alloc(32, sizeof(R) * N * 10);
    ii = (R*)aligned_alloc(32, sizeof(R) * N * 10);
    ro = (R*)aligned_alloc(32, sizeof(R) * N * 10);
    io = (R*)aligned_alloc(32, sizeof(R) * N * 10);
    is = (stride)aligned_alloc(32, sizeof(INT) * 10);
    os = (stride)aligned_alloc(32, sizeof(INT) * 10);

    for (INT idx = 0; idx < 10; ++idx) {
        is[idx] = idx * N;
        os[idx] = idx * N;
    }

    for (INT n = 0; n < N * 10; ++n) {
        ri[n] = (R)(rand() % 1000) / 100.0;
        ii[n] = (R)(rand() % 1000) / 100.0;
        ro[n] = 0.0;
        io[n] = 0.0;
    }
}