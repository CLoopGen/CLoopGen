#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;
INT i;

void init_vars() {
    const INT N = 1 << 20; // ~16 million elements, adjust for ~0.01s runtime

    v = N;
    ivs = 4;
    ovs = 4;

    R0 = (R*)aligned_alloc(32, sizeof(R) * (N * ivs + 8));
    R1 = (R*)aligned_alloc(32, sizeof(R) * (N * ivs + 8));
    Cr = (R*)aligned_alloc(32, sizeof(R) * (N * ovs + 8));
    Ci = (R*)aligned_alloc(32, sizeof(R) * (N * ovs + 8));

    rs = (stride)aligned_alloc(32, sizeof(INT) * 4);
    csr = (stride)aligned_alloc(32, sizeof(INT) * 4);
    csi = (stride)aligned_alloc(32, sizeof(INT) * 4);

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    csr[0] = 0;
    csr[1] = 1;
    csr[2] = 2;
    csr[3] = 3;

    csi[0] = 0;
    csi[1] = 1;
    csi[2] = 2;
    csi[3] = 3;

    for (INT j = 0; j < N * ivs; j++) {
        R0[j] = sin(j * 0.01);
        R1[j] = cos(j * 0.01);
    }

    for (INT j = 0; j < N * ovs; j++) {
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}