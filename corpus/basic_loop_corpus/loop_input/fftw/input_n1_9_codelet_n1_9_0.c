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
E KP939692620 = 0.9396926207859084;
E KP342020143 = 0.3420201433256687;
E KP984807753 = 0.984807753012208;
E KP173648177 = 0.17364817766693033;
E KP642787609 = 0.6427876096865393;
E KP766044443 = 0.766044443118978;
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386;
INT i;

static const INT DATA_SIZE = 1 << 22; // ~16 million elements, approx 128MB for doubles
static const INT VEC_LEN = 9;

void init_vars() {
    ri = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));
    ii = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));
    ro = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));
    io = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));
    is = (stride)aligned_alloc(64, VEC_LEN * sizeof(INT));
    os = (stride)aligned_alloc(64, VEC_LEN * sizeof(INT));

    for (INT j = 0; j < DATA_SIZE; ++j) {
        ri[j] = (R)(rand() % 1000) / 100.0;
        ii[j] = (R)(rand() % 1000) / 100.0;
        ro[j] = 0.0;
        io[j] = 0.0;
    }

    for (INT j = 0; j < VEC_LEN; ++j) {
        is[j] = j * 1;
        os[j] = j * 1;
    }

    v = DATA_SIZE / VEC_LEN;
    ivs = 1;
    ovs = 1;
}