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

E KP773010453 = 0.773010453;
E KP634393284 = 0.634393284;
E KP098017140 = 0.098017140;
E KP995184726 = 0.995184726;
E KP290284677 = 0.290284677;
E KP956940335 = 0.956940335;
E KP471396736 = 0.471396736;
E KP881921264 = 0.881921264;
E KP195090322 = 0.195090322;
E KP980785280 = 0.980785280;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;

INT i;

void init_vars() {
    const INT N = 32;
    const INT num_points = 1 << 20; // ~8MB per array, total ~32MB

    R0 = (R*)aligned_alloc(64, sizeof(R) * num_points * N);
    R1 = (R*)aligned_alloc(64, sizeof(R) * num_points * N);
    Cr = (R*)aligned_alloc(64, sizeof(R) * num_points * N);
    Ci = (R*)aligned_alloc(64, sizeof(R) * num_points * N);

    rs = (stride)aligned_alloc(64, sizeof(INT) * N);
    csr = (stride)aligned_alloc(64, sizeof(INT) * N);
    csi = (stride)aligned_alloc(64, sizeof(INT) * N);

    for (INT idx = 0; idx < N; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    for (INT k = 0; k < num_points * N; ++k) {
        R0[k] = sin(k * 0.01);
        R1[k] = cos(k * 0.01);
        Cr[k] = 0.0;
        Ci[k] = 0.0;
    }

    v = num_points;
    ivs = N;
    ovs = N;
}