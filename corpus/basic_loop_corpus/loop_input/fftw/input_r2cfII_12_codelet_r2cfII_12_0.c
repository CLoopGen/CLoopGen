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

E KP353553390 = 0.353553390;
E KP707106781 = 0.707106781;
E KP612372435 = 0.612372435;
E KP500000000 = 0.500000000;
E KP866025403 = 0.866025403;
INT i;

void init_vars() {
    const size_t data_size = 262144; // ~2MB of double data (per array), allows safe indexing with offsets

    R0 = (R*)aligned_alloc(64, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(64, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(64, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(64, data_size * sizeof(R));

    rs = (stride)aligned_alloc(64, 6 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 6 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 6 * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(idx % 128) / 64.0;
        R1[idx] = (R)((idx + 1) % 128) / 64.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    rs[0] = 0;   rs[1] = 1;   rs[2] = 2;   rs[3] = 3;   rs[4] = 4;   rs[5] = 5;
    csr[0] = 0;  csr[1] = 1;  csr[2] = 2;  csr[3] = 3;  csr[4] = 4;  csr[5] = 5;
    csi[0] = 0;  csi[1] = 1;  csi[2] = 2;  csi[3] = 3;  csi[4] = 4;  csi[5] = 5;

    ivs = 1;
    ovs = 1;
    v = 65536; // ensures loop runs enough iterations (~65k) to take ~0.01 sec with reasonable work per iteration
}