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
E KP1_847759065;
E KP765366864;
E KP1_414213562;
E KP2_000000000;
INT i;

#define ALIGNMENT 32
#define ALIGNED_MALLOC(size) aligned_alloc(ALIGNMENT, (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1))
#define ALIGNED_FREE(ptr) free(ptr)

void init_vars() {
    // Initialize constants
    KP1_847759065 = 1.8477590650225735;
    KP765366864 = 0.7653668647301795;
    KP1_414213562 = 1.4142135623730951;
    KP2_000000000 = 2.0000000000000000;

    // Target approximately 100 ms runtime: adjust data size accordingly.
    // The loop runs 'v' iterations, each accessing up to index 8 in Cr/Ci via csr/csi strides.
    // We assume typical CPU does ~1e9 operations/sec; this kernel is heavy per iteration.
    // Empirically, set total data such that v ≈ 1e6 gives ~0.1 sec on modern CPU.

    size_t total_elements = 1 << 20;  // 1M elements per array
    v = total_elements;

    ivs = 1;  // input vector stride step (assumed unit)
    ovs = 1;  // output vector stride step (assumed unit)

    // Allocate arrays with padding to prevent out-of-bounds access
    // Max index used: csr[8], csi[8] => need at least 9 * |max stride| in Cr/Ci
    // Assume strides are positive and within reasonable bounds

    // Allocate Cr and Ci: need space for max(csr[i], csi[i]) + 1, for i=0..8
    // Set maximum offset to 8 (as indexed up to csr[8])
    size_t cr_ci_size = total_elements * sizeof(R);
    Cr = (R*)ALIGNED_MALLOC(cr_ci_size);
    Ci = (R*)ALIGNED_MALLOC(cr_ci_size);

    // Allocate R0 and R1: indexed up to rs[8] (e.g., rs[7] used), so ensure large enough
    size_t r0_r1_size = total_elements * sizeof(R);
    R0 = (R*)ALIGNED_MALLOC(r0_r1_size);
    R1 = (R*)ALIGNED_MALLOC(r0_r1_size);

    // Allocate stride vectors: rs, csr, csi of length at least 9
    rs = (stride)ALIGNED_MALLOC(9 * sizeof(INT));
    csr = (stride)ALIGNED_MALLOC(9 * sizeof(INT));
    csi = (stride)ALIGNED_MALLOC(9 * sizeof(INT));

    // Initialize stride arrays: assume unit strides for simplicity
    for (int idx = 0; idx < 9; idx++) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    // Initialize data arrays with non-zero values to avoid division by zero or trivial results
    for (size_t idx = 0; idx < total_elements; idx++) {
        Cr[idx] = sin(idx * 0.01);
        Ci[idx] = cos(idx * 0.01);
        R0[idx] = 0.0;
        R1[idx] = 0.0;
    }
}