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
E KP559016994 = 0.559016994;
E KP951056516 = 0.951056516;
E KP587785252 = 0.587785252;

INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01s runtime
    const INT vector_length = 6; // must accommodate rs[4], csr[5], csi[4], etc.

    R0 = (R*)aligned_alloc(64, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(64, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(64, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(64, data_size * sizeof(R));

    rs = (stride)aligned_alloc(64, vector_length * sizeof(INT));
    csr = (stride)aligned_alloc(64, vector_length * sizeof(INT));
    csi = (stride)aligned_alloc(64, vector_length * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(idx % 100) / 100.0;
        R1[idx] = (R)((idx + 10) % 100) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3; rs[4] = 4;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3; csr[4] = 4; csr[5] = 5;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3; csi[4] = 4;

    v = data_size / 6; // ensure we don't exceed bounds with indexing via rs[4], etc.
    ivs = 6;
    ovs = 6;
}