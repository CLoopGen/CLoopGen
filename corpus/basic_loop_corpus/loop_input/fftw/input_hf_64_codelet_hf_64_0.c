#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef R E;
typedef ptrdiff_t INT;
typedef INT *stride;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP290284677 = 0.290284677;
E KP956940335 = 0.956940335;
E KP881921264 = 0.881921264;
E KP471396736 = 0.471396736;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP098017140 = 0.098017140;
E KP995184726 = 0.995184726;
E KP773010453 = 0.773010453;
E KP634393284 = 0.634393284;
E KP980785280 = 0.980785280;
E KP195090322 = 0.195090322;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;
INT m;

void init_vars() {
    const size_t N = 64;
    const size_t data_size = N * sizeof(R);
    const size_t w_size = N * 2 * sizeof(R); 
    const size_t stride_size = N * sizeof(INT);

    cr = (R*)aligned_alloc(64, data_size);
    ci = (R*)aligned_alloc(64, data_size);
    W = (R*)aligned_alloc(64, w_size);
    rs = (INT*)aligned_alloc(64, stride_size);

    for (size_t i = 0; i < N; i++) {
        cr[i] = (R)(i + 1) * 0.1;
        ci[i] = (R)(i + 1) * 0.05;
        rs[i] = (INT)i;
    }

    for (size_t i = 0; i < N * 2; i++) {
        W[i] = (R)(i % 126) * 0.01;
    }

    mb = 0;
    me = 1;
    ms = 1;
}