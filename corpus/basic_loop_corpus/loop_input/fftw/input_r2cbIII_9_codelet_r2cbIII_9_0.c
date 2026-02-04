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
E KP642787609 = 0.642787609;
E KP766044443 = 0.766044443;
E KP1_326827896 = 1.326827896;
E KP1_113340798 = 1.113340798;
E KP984807753 = 0.984807753;
E KP173648177 = 0.173648177;
E KP1_705737063 = 1.705737063;
E KP300767466 = 0.300767466;
E KP500000000 = 0.500000000;
E KP866025403 = 0.866025403;
E KP2_000000000 = 2.000000000;
E KP1_732050807 = 1.732050807;
INT i;

static const INT array_size = 1 << 20; // ~16MB of data, adjust for ~0.01s runtime
static const INT stride_size = 6;

void init_vars() {
    R0 = (R*)aligned_alloc(64, array_size * sizeof(R));
    R1 = (R*)aligned_alloc(64, array_size * sizeof(R));
    Cr = (R*)aligned_alloc(64, array_size * sizeof(R));
    Ci = (R*)aligned_alloc(64, array_size * sizeof(R));

    rs = (stride)aligned_alloc(64, stride_size * sizeof(INT));
    csr = (stride)aligned_alloc(64, stride_size * sizeof(INT));
    csi = (stride)aligned_alloc(64, stride_size * sizeof(INT));

    for (INT j = 0; j < array_size; ++j) {
        R0[j] = 0.0;
        R1[j] = 0.0;
        Cr[j] = (R)(rand()) / RAND_MAX;
        Ci[j] = (R)(rand()) / RAND_MAX;
    }

    for (INT j = 0; j < stride_size; ++j) {
        rs[j] = (j * 17) % 5 + 1;
        csr[j] = (j * 13) % 5 + 1;
        csi[j] = (j * 11) % 5 + 1;
    }

    v = 1 << 16; // Adjust loop count to hit ~0.01s on modern CPU
    ivs = 1;
    ovs = 1;

    if (R0 == NULL || R1 == NULL || Cr == NULL || Ci == NULL ||
        rs == NULL || csr == NULL || csi == NULL) {
        exit(1);
    }
}