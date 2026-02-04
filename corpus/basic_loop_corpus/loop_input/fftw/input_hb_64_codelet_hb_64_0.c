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
E KP098017140 = 0.0980171403295606;
E KP995184726 = 0.9951847266721969;
E KP773010453 = 0.7730104533627369;
E KP634393284 = 0.6343932841636455;
E KP471396736 = 0.4713967368259038;
E KP881921264 = 0.881921264348355;
E KP956940335 = 0.9569403357322088;
E KP290284677 = 0.2902846772544624;
E KP195090322 = 0.19509032201612825;
E KP980785280 = 0.9807852804032304;
E KP555570233 = 0.5555702330196022;
E KP831469612 = 0.8314696123025452;
E KP382683432 = 0.3826834323650898;
E KP923879532 = 0.9238795325112867;
E KP707106781 = 0.7071067811865476;
INT m;

void init_vars() {
    const size_t N = 64;
    const size_t data_size = sizeof(R) * N;
    
    cr = (R*)aligned_alloc(64, data_size);
    ci = (R*)aligned_alloc(64, data_size);
    W = (R*)aligned_alloc(64, sizeof(R) * 126);
    rs = (stride)aligned_alloc(64, sizeof(INT) * N);

    for (size_t i = 0; i < N; i++) {
        cr[i] = (R)(i + 1) * 0.01;
        ci[i] = (R)(i + 1) * 0.02;
        rs[i] = (INT)i;
    }
    
    for (int i = 0; i < 126; i++) {
        W[i] = (R)(i % 64) * 0.01;
    }

    mb = 1;
    me = 2;
    ms = 1;
}