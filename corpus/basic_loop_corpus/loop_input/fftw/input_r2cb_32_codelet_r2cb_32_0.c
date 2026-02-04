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

// Global pointers and variables
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
E KP1_662939224;
E KP1_111140466;
E KP1_961570560;
E KP390180644;
E KP765366864;
E KP1_847759065;
E KP707106781;
E KP1_414213562;
E KP2_000000000;
INT i;

// Helper constants based on typical FFTW-style access patterns
#define N 16  // implied by indices up to 15 in csr/csi/rs arrays

void init_vars() {
    // Initialize constants (common multipliers in FFT)
    KP1_662939224 = 1.662939224;
    KP1_111140466 = 1.111140466;
    KP1_961570560 = 1.961570560;
    KP390180644 = 0.390180644;
    KP765366864 = 0.765366864;
    KP1_847759065 = 1.847759065;
    KP707106781 = 0.707106781;
    KP1_414213562 = 1.414213562;
    KP2_000000000 = 2.000000000;

    // Allocate large enough data to make loop run ~0.01 sec
    // Assume each iteration processes 16 elements, aim for ~1M iterations -> ~16M elements per buffer
    size_t total_elements = 1 << 22;  // ~4 million elements (~32 MB per array)
    v = total_elements;

    // Stride vectors: assume unit strides for simplicity and safety
    rs = (stride)aligned_alloc(64, N * sizeof(INT));
    csr = (stride)aligned_alloc(64, N * sizeof(INT));
    csi = (stride)aligned_alloc(64, N * sizeof(INT));

    for (INT idx = 0; idx < N; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    // Stride increments
    ivs = 1;
    ovs = 1;

    // Allocate data arrays with padding to prevent out-of-bounds
    // Each access goes up to index 16, so we need at least 17 elements per "lane"
    size_t stride_unit = N + 1;
    size_t alloc_size_R = v * ovs * stride_unit * sizeof(R);
    size_t alloc_size_C = v * ivs * stride_unit * sizeof(R);

    R0 = (R*)aligned_alloc(64, alloc_size_R);
    R1 = (R*)aligned_alloc(64, alloc_size_R);
    Cr = (R*)aligned_alloc(64, alloc_size_C);
    Ci = (R*)aligned_alloc(64, alloc_size_C);

    // Initialize input data with non-zero values to simulate real FFT input
    for (size_t k = 0; k < v * ivs * stride_unit; ++k) {
        Cr[k] = sin(k * 0.01);
        Ci[k] = cos(k * 0.01);
    }
    for (size_t k = 0; k < v * ovs * stride_unit; ++k) {
        R0[k] = 0.0;
        R1[k] = 0.0;
    }
}