#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

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
E KP2_000000000 = 2.0;
E KP1_732050807 = 1.732050807;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data
    const size_t count = data_size / (sizeof(R) * 4); // Each loop uses 4 R elements

    v = (INT)(count > 0 ? count : 1);

    ivs = 1;
    ovs = 1;

    R0 = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    R1 = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    Cr = (R*)aligned_alloc(32, sizeof(R) * v * ivs);
    Ci = (R*)aligned_alloc(32, sizeof(R) * v * ivs);

    rs = (stride)malloc(sizeof(INT));
    csr = (stride)malloc(sizeof(INT));
    csi = (stride)malloc(sizeof(INT));

    rs[0] = 1;
    csr[0] = 1;
    csi[0] = 1;

    for (INT j = 0; j < v * ivs; ++j) {
        Cr[j] = (R)(j + 1);
        Ci[j] = (R)(j + 2);
    }
    for (INT j = 0; j < v * ovs; ++j) {
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}