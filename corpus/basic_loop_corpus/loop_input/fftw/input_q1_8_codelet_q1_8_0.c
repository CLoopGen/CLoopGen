#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double R;
typedef R E;
typedef ptrdiff_t INT;
typedef INT *stride;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *rio;
R *iio;
R *W;
stride rs;
stride vs;
INT mb;
INT me;
INT ms;
E KP707106781;
INT m;

#define N 131072

void init_vars() {
    rio = (R*)aligned_alloc(64, sizeof(R) * N);
    iio = (R*)aligned_alloc(64, sizeof(R) * N);
    W = (R*)aligned_alloc(64, sizeof(R) * 14);

    rs = (stride)aligned_alloc(64, sizeof(INT) * 8);
    vs = (stride)aligned_alloc(64, sizeof(INT) * 8);

    for (int i = 0; i < N; i++) {
        rio[i] = sin(i * 0.01);
        iio[i] = cos(i * 0.01);
    }

    for (int i = 0; i < 14; i++) {
        W[i] = sin(i * 0.1);
    }

    for (int i = 0; i < 8; i++) {
        rs[i] = i * 16;
        vs[i] = i * 32;
    }

    mb = 0;
    me = 1000;
    ms = 2;
    KP707106781 = 0.707106781;
}