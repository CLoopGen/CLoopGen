#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef R E;
typedef ptrdiff_t INT;
typedef INT *stride;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *ri;
R *ii;
R *ro;
R *io;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
E KP773010453 = 0.773010453;
E KP634393284 = 0.634393284;
E KP098017140 = 0.098017140;
E KP995184726 = 0.995184726;
E KP881921264 = 0.881921264;
E KP471396736 = 0.471396736;
E KP290284677 = 0.290284677;
E KP956940335 = 0.956940335;
E KP831469612 = 0.831469612;
E KP555570233 = 0.555570233;
E KP195090322 = 0.195090322;
E KP980785280 = 0.980785280;
E KP923879532 = 0.923879532;
E KP382683432 = 0.382683432;
E KP707106781 = 0.707106781;
INT i;

void init_vars() {
    const int N = 64;
    const int num_iters = 1000000 / N; // Approximate for ~0.01s on modern CPU

    v = num_iters;
    ivs = 1;
    ovs = 1;

    ri = (R*)aligned_alloc(64, sizeof(R) * N * v);
    ii = (R*)aligned_alloc(64, sizeof(R) * N * v);
    ro = (R*)aligned_alloc(64, sizeof(R) * N * v);
    io = (R*)aligned_alloc(64, sizeof(R) * N * v);
    is = (stride)aligned_alloc(64, sizeof(INT) * N);
    os = (stride)aligned_alloc(64, sizeof(INT) * N);

    for (int idx = 0; idx < N; ++idx) {
        is[idx] = idx;
        os[idx] = idx;
    }

    for (int iter = 0; iter < v; ++iter) {
        for (int j = 0; j < N; ++j) {
            ri[iter * N + j] = (R)(rand() % 1000) / 1000.0;
            ii[iter * N + j] = (R)(rand() % 1000) / 1000.0;
            ro[iter * N + j] = 0.0;
            io[iter * N + j] = 0.0;
        }
    }
}