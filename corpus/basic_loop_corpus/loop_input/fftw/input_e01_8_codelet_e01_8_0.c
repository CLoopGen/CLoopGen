#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *I;
R *O;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
E KP1_662939224 = 1.662939224;
E KP1_111140466 = 1.111140466;
E KP390180644 = 0.390180644;
E KP1_961570560 = 1.961570560;
E KP707106781 = 0.707106781;
E KP1_414213562 = 1.414213562;
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB for I and O (double arrays), ensures non-trivial runtime
    const INT vec_length = 8; // implied by is[7], os[7] access

    I = (R*)aligned_alloc(32, data_size * sizeof(R));
    O = (R*)aligned_alloc(32, data_size * sizeof(R));
    is = (INT*)aligned_alloc(32, vec_length * sizeof(INT));
    os = (INT*)aligned_alloc(32, vec_length * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        I[idx] = (R)(idx % 1000) / 1000.0;
    }

    for (INT j = 0; j < vec_length; ++j) {
        is[j] = j;
        os[j] = vec_length - 1 - j;
    }

    v = (INT)(data_size / vec_length); // number of full vector blocks
    ivs = vec_length;
    ovs = vec_length;

    if (v <= 0) {
        v = 1;
    }
}