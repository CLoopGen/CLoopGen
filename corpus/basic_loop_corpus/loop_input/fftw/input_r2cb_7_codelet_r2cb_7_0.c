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
E KP2_000000000;
E KP1_801937735;
E KP445041867;
E KP1_246979603;
E KP867767478;
E KP1_949855824;
E KP1_563662964;
INT i;

void init_vars() {
    KP2_000000000 = 2.0;
    KP1_801937735 = 1.801937735;
    KP445041867 = 0.445041867;
    KP1_246979603 = 1.246979603;
    KP867767478 = 0.867767478;
    KP1_949855824 = 1.949855824;
    KP1_563662964 = 1.563662964;

    size_t data_size = 1 << 20; // ~1MB of data per array (adjustable)
    R0 = (R*)aligned_alloc(64, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(64, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(64, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(64, data_size * sizeof(R));

    rs = (stride)aligned_alloc(64, 4 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 4 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 4 * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = (R)(rand() % 1000) / 100.0;
        Ci[idx] = (R)(rand() % 1000) / 100.0;
    }

    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3;
    csi[0] = 0; csi[1] = 1; csi[2] = 2; csi[3] = 3;

    ivs = 1;
    ovs = 1;

    v = (INT)(data_size / 4); // ensures safe access within bounds using offsets 0,1,2,3

    i = 0;
}