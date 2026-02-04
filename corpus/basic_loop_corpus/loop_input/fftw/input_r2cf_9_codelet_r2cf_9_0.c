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

E KP939692620 = 0.939692620;
E KP296198132 = 0.296198132;
E KP342020143 = 0.342020143;
E KP813797681 = 0.813797681;
E KP984807753 = 0.984807753;
E KP150383733 = 0.150383733;
E KP642787609 = 0.642787609;
E KP663413948 = 0.663413948;
E KP852868531 = 0.852868531;
E KP173648177 = 0.173648177;
E KP556670399 = 0.556670399;
E KP766044443 = 0.766044443;
E KP866025403 = 0.866025403;
E KP500000000 = 0.500000000;

INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double), total ~32MB
    const INT vector_length = 5;
    const INT num_vectors = data_size / (vector_length * sizeof(R));

    v = num_vectors;
    ivs = 5;
    ovs = 5;

    R0 = (R*)aligned_alloc(64, data_size);
    R1 = (R*)aligned_alloc(64, data_size);
    Cr = (R*)aligned_alloc(64, data_size);
    Ci = (R*)aligned_alloc(64, data_size);

    rs = (stride)aligned_alloc(64, 8 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 8 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 8 * sizeof(INT));

    for (size_t idx = 0; idx < data_size / sizeof(R); ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3; rs[4] = 4;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3; csr[4] = 4;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3; csi[4] = 4;

    for (int j = 5; j < 8; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }
}