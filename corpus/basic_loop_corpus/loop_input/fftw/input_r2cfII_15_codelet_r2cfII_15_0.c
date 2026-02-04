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

E KP500000000 = 0.500000000;
E KP866025403 = 0.866025403;
E KP809016994 = 0.809016994;
E KP309016994 = 0.309016994;
E KP250000000 = 0.250000000;
E KP559016994 = 0.559016994;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;

INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double)
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
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    for (INT idx = 0; idx < vector_length; ++idx) {
        rs[idx] = (ptrdiff_t)(idx);
        csr[idx] = (ptrdiff_t)(idx);
        csi[idx] = (ptrdiff_t)(idx);
    }

    v = (INT)(data_size / vector_length); 
    ivs = 8;
    ovs = 8;

    if (v <= 0) v = 1;
}