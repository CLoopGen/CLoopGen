#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>
#include <math.h>

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

E KP2_000000000 = 2.0;
E KP1_732050807 = 1.732050807;

INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to target ~0.01s runtime
    const INT vector_length = data_size / (sizeof(R) * 4); // 4 arrays: R0, R1, Cr, Ci

    v = (vector_length > 0) ? vector_length : 1;

    ivs = 1;
    ovs = 1;

    R0 = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    R1 = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    Cr = (R*)aligned_alloc(32, sizeof(R) * v * ivs);
    Ci = (R*)aligned_alloc(32, sizeof(R) * v * ivs);

    rs = (stride)aligned_alloc(32, sizeof(INT));
    csr = (stride)aligned_alloc(32, sizeof(INT));
    csi = (stride)aligned_alloc(32, sizeof(INT));

    rs[0] = 0; rs[1] = 1;
    csr[0] = 0; csr[1] = 1;
    csi[0] = 0; csi[1] = 1;

    for (INT idx = 0; idx < v * ovs; ++idx) {
        R0[idx] = 0.0;
        R1[idx] = 0.0;
    }

    for (INT idx = 0; idx < v * ivs; ++idx) {
        Cr[idx] = (R)(idx % 100) * 0.01;
        Ci[idx] = (R)((idx + 10) % 97) * 0.01;
    }
}