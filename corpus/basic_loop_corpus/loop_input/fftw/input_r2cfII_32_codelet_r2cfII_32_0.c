#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
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

E KP471396736 = 0.471396736;
E KP881921264 = 0.881921264;
E KP634393284 = 0.634393284;
E KP773010453 = 0.773010453;
E KP290284677 = 0.290284677;
E KP956940335 = 0.956940335;
E KP995184726 = 0.995184726;
E KP098017140 = 0.098017140;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP195090322 = 0.195090322;
E KP980785280 = 0.980785280;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;

INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double), total ~32MB
    const INT stride_size = 16;

    R0 = (R*)aligned_alloc(64, sizeof(R) * data_size);
    R1 = (R*)aligned_alloc(64, sizeof(R) * data_size);
    Cr = (R*)aligned_alloc(64, sizeof(R) * data_size);
    Ci = (R*)aligned_alloc(64, sizeof(R) * data_size);

    rs = (stride)aligned_alloc(64, sizeof(INT) * stride_size);
    csr = (stride)aligned_alloc(64, sizeof(INT) * stride_size);
    csi = (stride)aligned_alloc(64, sizeof(INT) * stride_size);

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = sin(idx * 0.01);
        R1[idx] = cos(idx * 0.01);
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    for (INT j = 0; j < stride_size; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    v = 1;
    ivs = 16;
    ovs = 16;

    for (i = 0; i < v; ++i) {
        R0 += ivs;
        R1 += ivs;
        Cr += ovs;
        Ci += ovs;
    }
    R0 -= v * ivs;
    R1 -= v * ivs;
    Cr -= v * ovs;
    Ci -= v * ovs;
}