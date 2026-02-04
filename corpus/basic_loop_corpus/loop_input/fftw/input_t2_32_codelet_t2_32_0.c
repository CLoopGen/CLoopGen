#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP195090322;
E KP980785280;
E KP555570233;
E KP831469612;
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

#define N (1 << 18)
#define ALIGNMENT 64

void init_vars() {
    mb = 0;
    ms = 32;
    m = mb;
    KP195090322 = 0.19509032201612825;
    KP980785280 = 0.9807852804032304;
    KP555570233 = 0.5555702330196022;
    KP831469612 = 0.8314696123025452;
    KP382683432 = 0.3826834323650898;
    KP923879532 = 0.9238795325112867;
    KP707106781 = 0.7071067811865476;

    posix_memalign((void**)&ri, ALIGNMENT, sizeof(R) * N);
    posix_memalign((void**)&ii, ALIGNMENT, sizeof(R) * N);
    posix_memalign((void**)&W, ALIGNMENT, sizeof(R) * (N / 4 + 8));
    posix_memalign((void**)&rs, ALIGNMENT, sizeof(INT) * 32);

    for (INT i = 0; i < N; i++) {
        ri[i] = (R)(i % 127) * 0.01;
        ii[i] = (R)((i * 37) % 199) * 0.01;
    }
    for (INT i = 0; i < (N / 4 + 8); i++) {
        W[i] = (R)(i % 97) * 0.001;
    }
    for (INT i = 0; i < 32; i++) {
        rs[i] = i * 2;
    }

    me = N / 32;
}