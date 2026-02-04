#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

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
E KP2_000000000 = 2.000000000;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of total data (adjustable)
    const INT vec_length = 5; // Maximum index used: csr[4], csi[4], rs[3] -> need at least 5 entries for indexed access

    // Allocate arrays with sufficient size
    Cr = (R*)aligned_alloc(64, sizeof(R) * data_size);
    Ci = (R*)aligned_alloc(64, sizeof(R) * data_size);
    R0 = (R*)aligned_alloc(64, sizeof(R) * data_size);
    R1 = (R*)aligned_alloc(64, sizeof(R) * data_size);

    // Initialize stride arrays
    csr = (stride)aligned_alloc(64, sizeof(INT) * vec_length);
    csi = (stride)aligned_alloc(64, sizeof(INT) * vec_length);
    rs = (stride)aligned_alloc(64, sizeof(INT) * vec_length);

    // Set meaningful strides (power-of-two or unit-stride patterns)
    for (INT idx = 0; idx < vec_length; ++idx) {
        csr[idx] = idx * 1;
        csi[idx] = idx * 1;
        rs[idx] = idx * 1;
    }

    // Set vectorization and loop parameters
    ivs = 1;
    ovs = 1;
    v = (data_size / 4) - 1; // Ensure i accesses within bounds: Cr[(csr[4])] => Cr[4] is valid if size >= 5*i_max
    if (v <= 0) v = 1;

    // Initialize Cr, Ci with non-zero test data to allow meaningful computation
    for (size_t j = 0; j < data_size; ++j) {
        Cr[j] = sin(j * 0.01);
        Ci[j] = cos(j * 0.01);
    }
    // Initialize output arrays to zero
    memset(R0, 0, sizeof(R) * data_size);
    memset(R1, 0, sizeof(R) * data_size);
}