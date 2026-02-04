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
E KP707106781;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB total working set
    const INT vec_length = 4;
    
    R0 = (R*)aligned_alloc(32, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(32, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(32, data_size * sizeof(R));

    rs = (stride)aligned_alloc(32, vec_length * sizeof(INT));
    csr = (stride)aligned_alloc(32, vec_length * sizeof(INT));
    csi = (stride)aligned_alloc(32, vec_length * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3; csr[4] = 4;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3; csi[4] = 4;

    v = 16384;
    ivs = 4;
    ovs = 4;
    KP707106781 = 0.707106781;
}