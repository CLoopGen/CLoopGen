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

E KP1_913880671 = 1.913880671;
E KP580569354 = 0.580569354;
E KP942793473 = 0.942793473;
E KP1_763842528 = 1.763842528;
E KP1_546020906 = 1.546020906;
E KP1_268786568 = 1.268786568;
E KP196034280 = 0.196034280;
E KP1_990369453 = 1.990369453;
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
E KP1_961570560 = 1.961570560;
E KP390180644 = 0.390180644;
E KP1_111140466 = 1.111140466;
E KP1_662939224 = 1.662939224;
E KP1_414213562 = 1.414213562;
E KP2_000000000 = 2.000000000;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;

INT i;

void init_vars() {
    const size_t N = 16;
    const size_t total_size = 16 * 1024 * 1024 / sizeof(R); // ~16MB of data -> ~0.01 sec estimate
    v = total_size / N;
    ivs = 1;
    ovs = 1;

    R0 = (R*)aligned_alloc(64, sizeof(R) * v * ovs * N);
    R1 = (R*)aligned_alloc(64, sizeof(R) * v * ovs * N);
    Cr = (R*)aligned_alloc(64, sizeof(R) * v * ivs * N);
    Ci = (R*)aligned_alloc(64, sizeof(R) * v * ivs * N);

    rs = (stride)aligned_alloc(64, sizeof(INT) * N);
    csr = (stride)aligned_alloc(64, sizeof(INT) * N);
    csi = (stride)aligned_alloc(64, sizeof(INT) * N);

    for (INT j = 0; j < N; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    for (size_t idx = 0; idx < v * ovs * N; ++idx) {
        R0[idx] = 0.0;
        R1[idx] = 0.0;
    }

    for (size_t idx = 0; idx < v * ivs * N; ++idx) {
        Cr[idx] = (R)(rand() % 1000) / 1000.0;
        Ci[idx] = (R)(rand() % 1000) / 1000.0;
    }
}