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
E KP1_118033988 = 1.118033988;
E KP500000000 = 0.5;
E KP1_902113032 = 1.902113032;
E KP1_175570504 = 1.175570504;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec runtime
    const size_t alignment = 32;

    // Allocate aligned memory
    R0 = aligned_alloc(alignment, data_size * sizeof(R));
    R1 = aligned_alloc(alignment, data_size * sizeof(R));
    Cr = aligned_alloc(alignment, data_size * sizeof(R));
    Ci = aligned_alloc(alignment, data_size * sizeof(R));

    rs = malloc(3 * sizeof(INT));
    csr = malloc(3 * sizeof(INT));
    csi = malloc(3 * sizeof(INT));

    // Set strides
    rs[0] = 0; rs[1] = 1; rs[2] = 2;
    csr[0] = 0; csr[1] = 1; csr[2] = 2;
    csi[0] = 0; csi[1] = 1; csi[2] = 2;

    // Set vector length and strides
    v = data_size / 8; // Adjust loop count for reasonable execution time
    ivs = 1;
    ovs = 1;

    // Initialize array contents to avoid NaN/undefined behavior
    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(idx % 100) * 0.1;
        R1[idx] = (R)(idx % 100) * 0.2;
        Cr[idx] = (R)(idx % 100) * 0.3;
        Ci[idx] = (R)(idx % 100) * 0.4;
    }
}