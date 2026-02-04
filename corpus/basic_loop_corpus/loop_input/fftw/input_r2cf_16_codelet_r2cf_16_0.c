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
E KP923879532 = 0.9238795325112867;
E KP382683432 = 0.3826834323650898;
E KP707106781 = 0.7071067811865476;
INT i;

void init_vars() {
    const INT N = 65536; 

    v = N;
    ivs = 8;
    ovs = 8;

    R0 = (R*)aligned_alloc(64, sizeof(R) * ivs * N);
    R1 = (R*)aligned_alloc(64, sizeof(R) * ivs * N);
    Cr = (R*)aligned_alloc(64, sizeof(R) * ovs * N);
    Ci = (R*)aligned_alloc(64, sizeof(R) * ovs * N);

    rs = (stride)aligned_alloc(64, sizeof(INT) * 8);
    csr = (stride)aligned_alloc(64, sizeof(INT) * 8);
    csi = (stride)aligned_alloc(64, sizeof(INT) * 8);

    for (INT idx = 0; idx < 8; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    for (INT idx = 0; idx < ivs * N; ++idx) {
        R0[idx] = (R)(idx % 128) * 0.01;
        R1[idx] = (R)((idx + 17) % 128) * 0.01;
    }

    for (INT idx = 0; idx < ovs * N; ++idx) {
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }
}