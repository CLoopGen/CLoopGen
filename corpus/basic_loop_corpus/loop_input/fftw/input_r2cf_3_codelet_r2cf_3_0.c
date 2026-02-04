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
E KP866025403 = 0.8660254037844386; // Approximate value for √3/2
E KP500000000 = 0.5;
INT i;

static size_t data_size = 1 << 24; // ~16M elements, roughly 128MB of total arrays

void init_vars() {
    // Allocate aligned memory for better performance and FFT-like access patterns
    R0 = aligned_alloc(64, data_size * sizeof(R));
    R1 = aligned_alloc(64, data_size * sizeof(R));
    Cr = aligned_alloc(64, data_size * sizeof(R));
    Ci = aligned_alloc(64, data_size * sizeof(R));

    rs = malloc(2 * sizeof(INT));
    csr = malloc(2 * sizeof(INT));
    csi = malloc(2 * sizeof(INT));

    // Initialize stride values to valid small offsets
    rs[0] = 0; rs[1] = 1;
    csr[0] = 0; csr[1] = 1;
    csi[0] = 0; csi[1] = 1;

    // Set vector length and strides
    v = data_size / 2;  // Ensure we don't exceed bounds with rs[1] indexing
    ivs = 2;            // Input vector stride (step by 2 to allow rs[1] = 1)
    ovs = 2;            // Output vector stride

    // Initialize input data to avoid NaN or extreme values
    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = sin(idx * 0.01);
        R1[idx] = cos(idx * 0.01);
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }
}