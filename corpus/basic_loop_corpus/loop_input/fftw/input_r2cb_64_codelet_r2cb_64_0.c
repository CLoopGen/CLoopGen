#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
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

E KP1_268786568 = 1.268786568;
E KP1_546020906 = 1.546020906;
E KP196034280 = 0.196034280;
E KP1_990369453 = 1.990369453;
E KP942793473 = 0.942793473;
E KP1_763842528 = 1.763842528;
E KP580569354 = 0.580569354;
E KP1_913880671 = 1.913880671;
E KP1_111140466 = 1.111140466;
E KP1_662939224 = 1.662939224;
E KP390180644 = 0.390180644;
E KP1_961570560 = 1.961570560;
E KP923879532 = 0.923879532;
E KP382683432 = 0.382683432;
E KP707106781 = 0.707106781;
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
E KP1_414213562 = 1.414213562;
E KP2_000000000 = 2.000000000;

INT i;

void init_vars() {
    const size_t N = 32;
    const size_t data_size = 1 << 20; // ~1MB per array, total ~8MB
    const size_t total_elements = data_size / sizeof(R);
    const size_t vec_length = total_elements / N;
    
    if (vec_length == 0) {
        fprintf(stderr, "Data size too small\n");
        exit(1);
    }

    R0 = (R*)aligned_alloc(64, total_elements * sizeof(R));
    R1 = (R*)aligned_alloc(64, total_elements * sizeof(R));
    Cr = (R*)aligned_alloc(64, total_elements * sizeof(R));
    Ci = (R*)aligned_alloc(64, total_elements * sizeof(R));

    rs = (stride)aligned_alloc(64, N * sizeof(INT));
    csr = (stride)aligned_alloc(64, N * sizeof(INT));
    csi = (stride)aligned_alloc(64, N * sizeof(INT));

    for (size_t j = 0; j < N; ++j) {
        rs[j] = (INT)j;
        csr[j] = (INT)j;
        csi[j] = (INT)j;
    }

    for (size_t j = 0; j < total_elements; ++j) {
        Cr[j] = sin(j * 0.01);
        Ci[j] = cos(j * 0.01);
        R0[j] = 0.0;
        R1[j] = 0.0;
    }

    v = vec_length;
    ivs = 1;
    ovs = 1;
}