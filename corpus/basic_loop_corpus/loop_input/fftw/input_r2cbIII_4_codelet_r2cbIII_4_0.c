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
E KP1_414213562;
E KP2_000000000;
INT i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(R))

void init_vars() {
    KP1_414213562 = 1.414213562;
    KP2_000000000 = 2.000000000;

    v = TOTAL_ELEMENTS / 2;
    ivs = 1;
    ovs = 2;

    R0 = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    R1 = (R*)aligned_alloc(32, sizeof(R) * v * ovs);
    Cr = (R*)aligned_alloc(32, sizeof(R) * v * ivs);
    Ci = (R*)aligned_alloc(32, sizeof(R) * v * ivs);

    rs = (stride)aligned_alloc(32, sizeof(INT));
    csr = (stride)aligned_alloc(32, sizeof(INT));
    csi = (stride)aligned_alloc(32, sizeof(INT));

    rs[1] = 1;
    csr[1] = 1;
    csi[1] = 1;

    for (INT idx = 0; idx < v * ivs; idx++) {
        Cr[idx] = (R)(idx % 100) / 100.0;
        Ci[idx] = (R)((idx + 10) % 100) / 100.0;
    }

    for (INT idx = 0; idx < v * ovs; idx++) {
        R0[idx] = 0.0;
        R1[idx] = 0.0;
    }
}