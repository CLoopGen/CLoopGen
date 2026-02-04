#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
INT m;

#define N 131072

void init_vars() {
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;

    cr = (R*)aligned_alloc(32, sizeof(R) * N * 2);
    ci = (R*)aligned_alloc(32, sizeof(R) * N * 2);
    W = (R*)aligned_alloc(32, sizeof(R) * N * 8);

    rs = (stride)aligned_alloc(32, sizeof(INT) * 20);
    for (int i = 0; i < 20; ++i) {
        rs[i] = i * 2;
    }

    ms = 1;
    mb = 1;
    me = N / 2 + 1;

    for (INT i = 0; i < N * 2; ++i) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }
    for (INT i = 0; i < N * 8; ++i) {
        W[i] = sin(i * 0.001) * cos(i * 0.002);
    }
}