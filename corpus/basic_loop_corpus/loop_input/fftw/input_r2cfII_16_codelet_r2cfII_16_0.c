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
E KP555570233;
E KP831469612;
E KP980785280;
E KP195090322;
E KP382683432;
E KP923879532;
E KP707106781;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double), total ~32MB for R0, R1, Cr, Ci
    const INT vector_length = 8;
    
    R0 = (R*)aligned_alloc(64, sizeof(R) * data_size);
    R1 = (R*)aligned_alloc(64, sizeof(R) * data_size);
    Cr = (R*)aligned_alloc(64, sizeof(R) * data_size);
    Ci = (R*)aligned_alloc(64, sizeof(R) * data_size);

    rs = (stride)aligned_alloc(64, sizeof(INT) * 8);
    csr = (stride)aligned_alloc(64, sizeof(INT) * 8);
    csi = (stride)aligned_alloc(64, sizeof(INT) * 8);

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(rand() % 1000) / 100.0;
        R1[idx] = (R)(rand() % 1000) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    for (int idx = 0; idx < 8; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    v = data_size / vector_length;
    ivs = 8;
    ovs = 8;

    KP555570233 = 0.555570233;
    KP831469612 = 0.831469612;
    KP980785280 = 0.980785280;
    KP195090322 = 0.195090322;
    KP382683432 = 0.382683432;
    KP923879532 = 0.923879532;
    KP707106781 = 0.707106781;

    i = 0;
}