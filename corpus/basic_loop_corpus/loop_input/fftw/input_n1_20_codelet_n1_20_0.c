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
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
INT i;

void init_vars() {
    const INT N = 20; 
    const INT data_size = 1 << 20; 
    v = data_size;
    ivs = 1;
    ovs = 1;

    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;

    ri = (R*)aligned_alloc(32, sizeof(R) * v * ivs);
    ii = (R*)aligned_alloc(32, sizeof(R) * v * ivs);
    ro = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    io = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    is = (INT*)aligned_alloc(32, sizeof(INT) * N);
    os = (INT*)aligned_alloc(32, sizeof(INT) * N);

    for (INT j = 0; j < N; ++j) {
        is[j] = j;
        os[j] = j;
    }

    for (INT j = 0; j < v * ivs; ++j) {
        ri[j] = sin(j * 0.01);
        ii[j] = cos(j * 0.01);
    }

    memset(ro, 0, sizeof(R) * v * ovs);
    memset(io, 0, sizeof(R) * v * ovs);
}