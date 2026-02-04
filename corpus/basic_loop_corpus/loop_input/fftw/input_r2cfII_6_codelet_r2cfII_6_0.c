#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

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
E KP500000000 = 0.5;
E KP866025403 = 0.866025403;

INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double)
    const INT vec_length = data_size / sizeof(R);

    R0 = (R*)aligned_alloc(32, data_size);
    R1 = (R*)aligned_alloc(32, data_size);
    Cr = (R*)aligned_alloc(32, data_size);
    Ci = (R*)aligned_alloc(32, data_size);

    rs = (stride)aligned_alloc(32, 3 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 3 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 3 * sizeof(INT));

    for (size_t idx = 0; idx < data_size / sizeof(R); ++idx) {
        R0[idx] = (R)(idx % 100) * 0.1;
        R1[idx] = (R)((idx + 13) % 100) * 0.1;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    rs[0] = 0; rs[1] = 1; rs[2] = 2;
    csr[0] = 0; csr[1] = 1; csr[2] = 2;
    csi[0] = 0; csi[1] = 1; csi[2] = 2;

    v = vec_length / 3;
    ivs = 3;
    ovs = 3;
}