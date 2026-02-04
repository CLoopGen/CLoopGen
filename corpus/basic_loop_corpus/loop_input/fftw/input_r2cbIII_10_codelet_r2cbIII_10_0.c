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
E KP1_902113032 = 1.902113032590307;
E KP1_175570504 = 1.175570504584946;
E KP2_000000000 = 2.0;
E KP1_118033988 = 1.118033988749895;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double precision)
    v = data_size;
    ivs = 1;
    ovs = 1;

    R0 = (R*)aligned_alloc(64, v * 5 * sizeof(R));
    R1 = (R*)aligned_alloc(64, v * 5 * sizeof(R));
    Cr = (R*)aligned_alloc(64, v * 5 * sizeof(R));
    Ci = (R*)aligned_alloc(64, v * 5 * sizeof(R));

    rs = (stride)aligned_alloc(64, 5 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 5 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 5 * sizeof(INT));

    for (int j = 0; j < 5; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    for (size_t j = 0; j < v * 5; ++j) {
        Cr[j] = (R)(drand48());
        Ci[j] = (R)(drand48());
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}