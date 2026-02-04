#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total input data for ~0.01s runtime estimate
    const INT vector_length = data_size / (sizeof(R) * 4); // each iteration uses 4 R values: R0[0], R0[rs[1]], R1[0], R1[rs[1]]

    v = (vector_length > 0) ? vector_length : 1;
    ivs = 2; // input stride increment per iteration
    ovs = 3; // output stride increment per iteration

    // Allocate buffers with padding to prevent out-of-bounds access
    R0 = (R*)aligned_alloc(64, sizeof(R) * (v * ivs + 2));
    R1 = (R*)aligned_alloc(64, sizeof(R) * (v * ivs + 2));
    Cr = (R*)aligned_alloc(64, sizeof(R) * (v * ovs + 4));
    Ci = (R*)aligned_alloc(64, sizeof(R) * (v * ovs + 4));

    rs = (INT*)aligned_alloc(64, sizeof(INT) * 2);
    csr = (INT*)aligned_alloc(64, sizeof(INT) * 3);
    csi = (INT*)aligned_alloc(64, sizeof(INT) * 3);

    // Initialize strides
    rs[1] = 1;
    csr[1] = 1;
    csr[2] = 2;
    csi[1] = 1;
    csi[2] = 2;

    // Initialize data arrays to non-zero values for meaningful computation
    for (INT j = 0; j < v * ivs + 2; j++) {
        R0[j] = sin(j * 0.01);
        R1[j] = cos(j * 0.01);
    }
    for (INT j = 0; j < v * ovs + 4; j++) {
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }

    // Ensure initial pointer offsets are valid
    i = v;
}