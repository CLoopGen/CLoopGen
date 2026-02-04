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
E KP500000000;
E KP1_902113032;
E KP1_175570504;
E KP2_000000000;
E KP1_118033988;
INT i;

void init_vars() {
    const INT N = 1 << 20; // ~16M elements, adjust for ~0.01s runtime

    v = N;
    ivs = 1;
    ovs = 1;

    KP500000000 = 0.5;
    KP1_902113032 = 1.902113032;
    KP1_175570504 = 1.175570504;
    KP2_000000000 = 2.0;
    KP1_118033988 = 1.118033988;

    R0 = (R*)aligned_alloc(32, sizeof(R) * 5 * N);
    R1 = (R*)aligned_alloc(32, sizeof(R) * 5 * N);
    Cr = (R*)aligned_alloc(32, sizeof(R) * 6 * N);
    Ci = (R*)aligned_alloc(32, sizeof(R) * 5 * N);

    rs = (stride)aligned_alloc(32, sizeof(INT) * 5);
    csr = (stride)aligned_alloc(32, sizeof(INT) * 6);
    csi = (stride)aligned_alloc(32, sizeof(INT) * 5);

    for (INT idx = 0; idx < 5; ++idx) {
        rs[idx] = idx;
        csi[idx] = idx;
    }
    for (INT idx = 0; idx < 6; ++idx) {
        csr[idx] = idx;
    }

    for (INT idx = 0; idx < 5 * N; ++idx) {
        R0[idx] = (R)(idx % 1234) / 1234.0;
        R1[idx] = (R)(idx % 1234) / 1234.0;
        if (idx < 6 * N) Cr[idx] = (R)(idx % 1234) / 1234.0;
        if (idx < 5 * N) Ci[idx] = (R)(idx % 1234) / 1234.0;
    }
}