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
E KP250000000 = 0.25;
E KP559016994 = 0.559016994;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024; 
    v = data_size;
    ivs = 1;
    ovs = 1;

    R0 = (R*)aligned_alloc(32, sizeof(R) * data_size * 3);
    R1 = (R*)aligned_alloc(32, sizeof(R) * data_size * 3);
    Cr = (R*)aligned_alloc(32, sizeof(R) * data_size * 3);
    Ci = (R*)aligned_alloc(32, sizeof(R) * data_size * 3);

    rs = (stride)aligned_alloc(32, sizeof(INT) * 3);
    csr = (stride)aligned_alloc(32, sizeof(INT) * 3);
    csi = (stride)aligned_alloc(32, sizeof(INT) * 3);

    rs[0] = 0; rs[1] = 1; rs[2] = 2;
    csr[0] = 0; csr[1] = 1; csr[2] = 2;
    csi[0] = 0; csi[1] = 1; csi[2] = 2;

    for (size_t idx = 0; idx < data_size * 3; ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }
}