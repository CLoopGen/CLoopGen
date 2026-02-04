#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Define all external variables
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
E KP1_961570560 = 1.961570560;
E KP390180644 = 0.390180644;
E KP1_111140466 = 1.111140466;
E KP1_662939224 = 1.662939224;
E KP707106781 = 0.707106781;
E KP1_414213562 = 1.414213562;
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
E KP2_000000000 = 2.000000000;
INT i;

// Helper function to initialize variables
void init_vars() {
    // We need at least 8 elements for each array due to indexing like csr[7], csi[7], rs[7], etc.
    const INT N = 8;
    const size_t data_size = (1 << 20) / sizeof(R); // ~1MB of data per array
    v = data_size / N;  // number of vector iterations

    // Allocate arrays with sufficient size
    Cr = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Ci = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    R0 = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    R1 = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));

    // Allocate strides
    rs = (INT*)aligned_alloc(sizeof(INT), N * sizeof(INT));
    csr = (INT*)aligned_alloc(sizeof(INT), N * sizeof(INT));
    csi = (INT*)aligned_alloc(sizeof(INT), N * sizeof(INT));

    // Initialize stride values: assume unit strides for simplicity
    for (INT idx = 0; idx < N; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    // Set vector strides
    ivs = 1;
    ovs = 1;

    // Initialize input data to prevent NaN/undefined behavior
    for (size_t j = 0; j < data_size; ++j) {
        Cr[j] = (R)(j % 100) / 100.0;
        Ci[j] = (R)((j + 10) % 100) / 100.0;
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}