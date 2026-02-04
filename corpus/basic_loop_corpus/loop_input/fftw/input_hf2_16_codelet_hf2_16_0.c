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
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

#define N 65536

void init_vars() {
    KP382683432 = 0.382683432;
    KP923879532 = 0.923879532;
    KP707106781 = 0.707106781;

    cr = (R*)aligned_alloc(64, sizeof(R) * N * 16);
    ci = (R*)aligned_alloc(64, sizeof(R) * N * 16);
    W = (R*)aligned_alloc(64, sizeof(R) * 8 * N);

    rs = (stride)aligned_alloc(64, sizeof(INT) * 16);
    for (int i = 0; i < 16; i++) {
        rs[i] = i;
    }

    for (INT i = 0; i < N * 16; i++) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }

    for (INT i = 0; i < N * 8; i++) {
        W[i] = sin(i * 0.02);
    }

    mb = 0;
    me = N;
    ms = 1;
}