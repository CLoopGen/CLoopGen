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
E KP866025403 = 0.8660254037844386;
E KP500000000 = 0.5;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of data per array (adjustable)
    const INT vector_length = 6;

    R0 = aligned_alloc(64, data_size * sizeof(R));
    R1 = aligned_alloc(64, data_size * sizeof(R));
    Cr = aligned_alloc(64, data_size * sizeof(R));
    Ci = aligned_alloc(64, data_size * sizeof(R));

    rs = malloc(vector_length * sizeof(INT));
    csr = malloc(vector_length * sizeof(INT));
    csi = malloc(vector_length * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    for (INT j = 0; j < vector_length; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    v = 100000; 
    ivs = 1;
    ovs = 1;
}