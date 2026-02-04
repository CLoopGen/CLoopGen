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
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to process
    const INT vector_length = 1024; // Number of iterations

    // Allocate input and output arrays with appropriate padding
    R0 = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    R1 = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Cr = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    Ci = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));

    // Set strides
    ivs = 1; // Input stride
    ovs = 1; // Output stride

    // Initialize stride pointers (though they are not used due to zero addition)
    rs = &ivs;
    csr = &ovs;
    csi = &ovs;

    // Set loop count
    v = vector_length;

    // Initialize array elements to avoid undefined behavior
    for (INT j = 0; j < data_size; ++j) {
        R0[j] = (R)(j + 1);
        R1[j] = (R)(-(j + 1));
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}