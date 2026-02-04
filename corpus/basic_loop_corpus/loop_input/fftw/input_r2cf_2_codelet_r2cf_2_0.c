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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data
    const size_t num_elements = data_size / sizeof(R);

    R0 = (R*)aligned_alloc(32, num_elements * sizeof(R));
    R1 = (R*)aligned_alloc(32, num_elements * sizeof(R));
    Cr = (R*)aligned_alloc(32, num_elements * sizeof(R));
    Ci = (R*)aligned_alloc(32, num_elements * sizeof(R));

    static INT rs_data[1] = {0};
    static INT csr_data[2] = {0, 1};
    static INT csi_data[2] = {0, 1};

    rs = rs_data;
    csr = csr_data;
    csi = csi_data;

    ivs = 1;
    ovs = 1;

    v = num_elements / 2;

    for (size_t idx = 0; idx < num_elements; ++idx) {
        R0[idx] = (R)(idx + 1);
        R1[idx] = (R)(idx * 2);
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }
}