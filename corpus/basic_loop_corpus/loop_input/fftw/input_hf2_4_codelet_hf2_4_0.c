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
INT m;

static const size_t DATA_SIZE_MB = 64;
static const size_t TOTAL_ELEMENTS = (DATA_SIZE_MB * (1 << 20)) / sizeof(R);

void init_vars() {
    mb = 1;
    me = TOTAL_ELEMENTS / 8;
    ms = 1;
    
    cr = (R*)aligned_alloc(32, TOTAL_ELEMENTS * sizeof(R));
    ci = (R*)aligned_alloc(32, TOTAL_ELEMENTS * sizeof(R));
    W = (R*)aligned_alloc(32, (me - mb + 1) * 4 * sizeof(R));
    rs = (stride)aligned_alloc(32, 4 * sizeof(INT));

    for (size_t i = 0; i < TOTAL_ELEMENTS; ++i) {
        cr[i] = (R)(rand() % 1000) / 100.0;
        ci[i] = (R)(rand() % 1000) / 100.0;
    }

    for (INT i = 0; i < (me - mb + 1) * 4; ++i) {
        W[i] = (R)(rand() % 1000) / 100.0;
    }

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;
}