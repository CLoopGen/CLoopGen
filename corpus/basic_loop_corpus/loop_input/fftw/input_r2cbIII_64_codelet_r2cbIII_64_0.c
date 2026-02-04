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

E KP1_343117909 = 1.343117909;
E KP1_481902250 = 1.481902250;
E KP1_807978586 = 1.807978586;
E KP855110186 = 0.855110186;
E KP1_997590912 = 1.997590912;
E KP098135348 = 0.98135348;
E KP673779706 = 0.673779706;
E KP1_883088130 = 1.883088130;
E KP195090322 = 0.195090322;
E KP980785280 = 0.980785280;
E KP1_191398608 = 1.191398608;
E KP1_606415062 = 1.606415062;
E KP1_715457220 = 1.715457220;
E KP1_028205488 = 1.028205488;
E KP1_978353019 = 1.978353019;
E KP293460948 = 0.293460948;
E KP485960359 = 0.485960359;
E KP1_940062506 = 1.940062506;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP1_268786568 = 1.268786568;
E KP1_546020906 = 1.546020906;
E KP1_763842528 = 1.763842528;
E KP942793473 = 0.942793473;
E KP1_990369453 = 1.990369453;
E KP196034280 = 0.196034280;
E KP580569354 = 0.580569354;
E KP1_913880671 = 1.913880671;
E KP1_662939224 = 1.662939224;
E KP1_111140466 = 1.111140466;
E KP390180644 = 0.390180644;
E KP1_961570560 = 1.961570560;
E KP765366864 = 0.765366864;
E KP1_847759065 = 1.847759065;
E KP1_414213562 = 1.414213562;
E KP2_000000000 = 2.000000000;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;

INT i;

void init_vars() {
    const size_t N = 32;
    const size_t data_size = 1 << 20; // ~1MB per array, allows for many iterations
    const INT total_elements = data_size / sizeof(R);
    v = total_elements / N; // Ensure we have enough blocks of size N

    if (v <= 0) v = 1;

    R0 = (R*)aligned_alloc(32, data_size);
    R1 = (R*)aligned_alloc(32, data_size);
    Cr = (R*)aligned_alloc(32, data_size);
    Ci = (R*)aligned_alloc(32, data_size);

    rs = (stride)aligned_alloc(32, N * sizeof(INT));
    csr = (stride)aligned_alloc(32, N * sizeof(INT));
    csi = (stride)aligned_alloc(32, N * sizeof(INT));

    ivs = 1;
    ovs = 1;

    for (INT j = 0; j < N; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    for (INT j = 0; j < total_elements; ++j) {
        Cr[j] = (R)(rand() % 1000) / 100.0;
        Ci[j] = (R)(rand() % 1000) / 100.0;
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}