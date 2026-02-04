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

E KP1_118033988 = 1.118033988;
E KP1_902113032 = 1.902113032;
E KP1_175570504 = 1.175570504;
E KP500000000 = 0.500000000;
E KP866025403 = 0.866025403;
E KP2_000000000 = 2.000000000;
E KP1_732050807 = 1.732050807;

INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double precision)
    const INT vector_length = 8;
    
    R0 = (R*)aligned_alloc(64, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(64, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(64, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(64, data_size * sizeof(R));

    rs = (stride)aligned_alloc(64, vector_length * sizeof(INT));
    csr = (stride)aligned_alloc(64, vector_length * sizeof(INT));
    csi = (stride)aligned_alloc(64, vector_length * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = (R)(rand() % 1000) / 100.0;
        Ci[idx] = (R)(rand() % 1000) / 100.0;
    }

    for (INT j = 0; j < vector_length; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    v = (INT)(data_size / vector_length);
    ivs = 1;
    ovs = 1;

    i = v;
}