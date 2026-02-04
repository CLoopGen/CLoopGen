#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
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
E KP2_000000000 = 2.0;
E KP083333333 = 0.833333333;
E KP251768516 = 0.251768516;
E KP075902986 = 0.075902986;
E KP132983124 = 0.132983124;
E KP258260390 = 0.258260390;
E KP1_732050807 = 1.732050807;
E KP300238635 = 0.300238635;
E KP011599105 = 0.011599105;
E KP156891391 = 0.156891391;
E KP256247671 = 0.256247671;
E KP174138601 = 0.174138601;
E KP575140729 = 0.575140729;
E KP503537032 = 0.503537032;
E KP113854479 = 0.113854479;
E KP265966249 = 0.265966249;
E KP387390585 = 0.387390585;
E KP866025403 = 0.866025403;
E KP300462606 = 0.300462606;
E KP500000000 = 0.5;
INT i;

void init_vars() {
    const INT N = 16;
    const INT data_size_per_array = 1 << 20; // ~1MB per array, adjust as needed for timing
    const INT total_elements = data_size_per_array / sizeof(R);
    
    v = total_elements / N;
    if (v <= 0) v = 1;

    ivs = 1;
    ovs = 1;

    ri = (R*)aligned_alloc(64, total_elements * sizeof(R));
    ii = (R*)aligned_alloc(64, total_elements * sizeof(R));
    ro = (R*)aligned_alloc(64, total_elements * sizeof(R));
    io = (R*)aligned_alloc(64, total_elements * sizeof(R));

    is = (stride)aligned_alloc(64, N * sizeof(INT));
    os = (stride)aligned_alloc(64, N * sizeof(INT));

    for (INT idx = 0; idx < N; ++idx) {
        is[idx] = idx;
        os[idx] = idx;
    }

    for (INT j = 0; j < total_elements; ++j) {
        ri[j] = sin(j * 0.01);
        ii[j] = cos(j * 0.01);
        ro[j] = 0.0;
        io[j] = 0.0;
    }
}