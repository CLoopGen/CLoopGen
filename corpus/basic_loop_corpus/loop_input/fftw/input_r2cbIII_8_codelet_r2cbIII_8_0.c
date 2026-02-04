#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *R0;
R *R1;
R *Cr;
R *Ci;
stride rs;
stride csr;
stride csi;
INT v;
INT ivs;
INT ovs;
E KP1_414213562 = 1.414213562;
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
E KP2_000000000 = 2.000000000;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double precision), adjust for ~0.01s runtime
    const INT vec_length = data_size / sizeof(R);

    v = vec_length;
    ivs = 1;
    ovs = 1;

    R0 = (R*)aligned_alloc(32, data_size);
    R1 = (R*)aligned_alloc(32, data_size);
    Cr = (R*)aligned_alloc(32, data_size);
    Ci = (R*)aligned_alloc(32, data_size);

    rs = (stride)aligned_alloc(32, 4 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 4 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 4 * sizeof(INT));

    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3;

    for (INT j = 0; j < vec_length; ++j) {
        Cr[j] = (R)(j % 100) * 0.01;
        Ci[j] = (R)((j + 10) % 100) * 0.01;
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}