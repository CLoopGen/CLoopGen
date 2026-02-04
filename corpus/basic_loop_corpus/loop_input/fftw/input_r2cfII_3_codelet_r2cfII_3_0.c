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
E KP500000000 = 0.5;
E KP866025403 = 0.866025403;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M doubles = 512MB total allocation target
    const size_t count = data_size / (sizeof(R) * 4); // each loop uses 4 R elements

    // Ensure at least one iteration
    v = (count > 0) ? count : 1;

    ivs = 1;
    ovs = 1;

    // Allocate arrays with padding to prevent out-of-bounds access
    R0 = (R*)aligned_alloc(32, (v + 2) * sizeof(R));
    R1 = (R*)aligned_alloc(32, (v + 2) * sizeof(R));
    Cr = (R*)aligned_alloc(32, (v + 2) * sizeof(R));
    Ci = (R*)aligned_alloc(32, (v + 2) * sizeof(R));

    // Allocate strides
    rs = (stride)aligned_alloc(32, 2 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 2 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 2 * sizeof(INT));

    // Initialize stride values
    rs[1] = 1;
    csr[1] = 1;

    // Initialize array elements to avoid NaN or undefined behavior
    for (INT j = 0; j < v + 2; ++j) {
        R0[j] = j * 0.1;
        R1[j] = j * 0.2;
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}