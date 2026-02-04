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
E KP250000000 = 0.250000000;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP559016994 = 0.559016994;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (adjustable)
    const INT vector_length = 5; // implied by rs[4] access

    // Allocate arrays with sufficient size to avoid out-of-bounds
    R0 = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    R1 = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Cr = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Ci = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));

    // Allocate and initialize stride arrays
    rs = (INT*)aligned_alloc(sizeof(INT), vector_length * sizeof(INT));
    csr = (INT*)aligned_alloc(sizeof(INT), vector_length * sizeof(INT));
    csi = (INT*)aligned_alloc(sizeof(INT), vector_length * sizeof(INT));

    // Initialize strides: assume unit strides for simplicity
    for (INT idx = 0; idx < vector_length; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    // Set vector count and strides
    v = data_size / vector_length; // number of vector iterations
    ivs = 1; // input vector stride step
    ovs = 1; // output vector stride step

    // Initialize input data to prevent undefined behavior
    for (size_t j = 0; j < data_size; ++j) {
        R0[j] = (R)(j % 100) * 0.1;
        R1[j] = (R)((j + 10) % 100) * 0.1;
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}