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
E KP2_000000000;
E KP1_118033988;
E KP500000000;
E KP1_175570504;
E KP1_902113032;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to target ~0.01s runtime
    const size_t num_elements = data_size / sizeof(R);

    R0 = (R*)aligned_alloc(64, num_elements * sizeof(R));
    R1 = (R*)aligned_alloc(64, num_elements * sizeof(R));
    Cr = (R*)aligned_alloc(64, num_elements * sizeof(R));
    Ci = (R*)aligned_alloc(64, num_elements * sizeof(R));

    rs = (stride)aligned_alloc(64, 3 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 3 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 3 * sizeof(INT));

    for (size_t idx = 0; idx < num_elements; ++idx) {
        R0[idx] = 0.0;
        R1[idx] = 0.0;
        Cr[idx] = (R)(rand() % 1000) / 100.0;
        Ci[idx] = (R)(rand() % 1000) / 100.0;
    }

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;

    csr[0] = 0;
    csr[1] = 1;
    csr[2] = 2;

    csi[0] = 0;
    csi[1] = 1;
    csi[2] = 2;

    v = num_elements / 3; // Ensure we access only valid thirds due to indexing with [csr[2]], etc.
    ivs = 1;
    ovs = 1;

    KP2_000000000 = 2.0;
    KP1_118033988 = 1.118033988;
    KP500000000 = 0.5;
    KP1_175570504 = 1.175570504;
    KP1_902113032 = 1.902113032;

    i = v;
}