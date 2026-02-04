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
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
E KP390180644 = 0.390180644;
E KP1_961570560 = 1.961570560;
E KP2_000000000 = 2.000000000;
E KP1_414213562 = 1.414213562;
E KP1_111140466 = 1.111140466;
E KP1_662939224 = 1.662939224;
E KP707106781 = 0.707106781;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of input/output data (1M doubles)
    I = (R*)aligned_alloc(64, data_size * sizeof(R));
    O = (R*)aligned_alloc(64, data_size * sizeof(R));
    is = (INT*)aligned_alloc(64, 8 * sizeof(INT));
    os = (INT*)aligned_alloc(64, 8 * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        I[idx] = (R)(idx % 1000) / 1000.0;
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        O[idx] = 0.0;
    }

    is[0] = 0; is[1] = 1; is[2] = 2; is[3] = 3;
    is[4] = 4; is[5] = 5; is[6] = 6; is[7] = 7;

    os[0] = 0; os[1] = 1; os[2] = 2; os[3] = 3;
    os[4] = 4; os[5] = 5; os[6] = 6; os[7] = 7;

    ivs = 8;
    ovs = 8;
    v = data_size / 8;
}