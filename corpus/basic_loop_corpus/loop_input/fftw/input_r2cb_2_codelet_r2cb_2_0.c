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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to target ~0.01s runtime
    const size_t num_elements = data_size / (sizeof(R) * 4); // Approximate for 4 arrays

    R0 = aligned_alloc(32, sizeof(R) * num_elements * 2);
    R1 = aligned_alloc(32, sizeof(R) * num_elements * 2);
    Cr = aligned_alloc(32, sizeof(R) * num_elements * 2);
    Ci = aligned_alloc(32, sizeof(R) * num_elements * 2);

    rs = malloc(sizeof(INT));
    csr = malloc(sizeof(INT));
    csi = malloc(sizeof(INT));

    *rs = 1;
    *csr = 1;
    *csi = 1;

    ivs = 1;
    ovs = 1;
    v = num_elements;

    for (INT idx = 0; idx < num_elements * 2; ++idx) {
        Cr[idx] = (R)(idx % 1000) / 10.0;
        Ci[idx] = (R)((idx + 500) % 1000) / 15.0;
        R0[idx] = 0.0;
        R1[idx] = 0.0;
    }
}