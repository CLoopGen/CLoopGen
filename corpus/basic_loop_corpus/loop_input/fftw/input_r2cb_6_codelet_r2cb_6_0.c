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
E KP2_000000000 = 2.0;
E KP1_732050807 = 1.732050807;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to target ~0.01s runtime
    const INT vector_length = 65536; // Number of iterations

    R0 = (R*)aligned_alloc(32, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(32, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(32, data_size * sizeof(R));

    rs = (stride)aligned_alloc(32, 4 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 4 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 4 * sizeof(INT));

    // Initialize strides
    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3;

    // Set vector and stride parameters
    v = vector_length;
    ivs = 1;
    ovs = 1;

    // Initialize input arrays with non-zero values to allow meaningful computation
    for (INT idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(idx % 1000) / 1000.0;
        R1[idx] = (R)((idx + 10) % 1000) / 1000.0;
        Cr[idx] = (R)((idx + 20) % 1000) / 1000.0;
        Ci[idx] = (R)((idx + 30) % 1000) / 1000.0;
    }
}