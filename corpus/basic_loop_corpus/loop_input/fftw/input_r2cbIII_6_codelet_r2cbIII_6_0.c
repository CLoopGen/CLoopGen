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
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec runtime
    const size_t vec_len = data_size / sizeof(R);

    v = vec_len / 3; // ensures Cr, Ci accessed at indices 0,1,2 -> needs at least 3*ivs
    ivs = 1;
    ovs = 1;

    // Allocate arrays with padding to prevent out-of-bounds access
    Cr = (R*)aligned_alloc(32, (3 * v * ivs + 1) * sizeof(R));
    Ci = (R*)aligned_alloc(32, (3 * v * ivs + 1) * sizeof(R));
    R0 = (R*)aligned_alloc(32, (3 * v * ovs + 1) * sizeof(R));
    R1 = (R*)aligned_alloc(32, (3 * v * ovs + 1) * sizeof(R));

    rs = (stride)malloc(4 * sizeof(INT));
    csr = (stride)malloc(4 * sizeof(INT));
    csi = (stride)malloc(4 * sizeof(INT));

    // Initialize stride tables
    rs[0] = 0; rs[1] = 1; rs[2] = 2;
    csr[0] = 0; csr[1] = 1; csr[2] = 2;
    csi[0] = 0; csi[1] = 1; csi[2] = 2;

    // Initialize data arrays to non-zero to allow meaningful computation
    for (INT j = 0; j < 3 * v * ivs + 1; ++j) {
        Cr[j] = (R)(j % 127) * 0.01;
        Ci[j] = (R)((j + 19) % 127) * 0.01;
    }
    for (INT j = 0; j < 3 * v * ovs + 1; ++j) {
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}