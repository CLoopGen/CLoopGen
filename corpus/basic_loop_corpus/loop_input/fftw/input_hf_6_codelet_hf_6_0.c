#include <stdio.h>
#include <inttypes.h>
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
E KP500000000;
E KP866025403;
INT m;

#define N (1 << 20)

void init_vars() {
    KP500000000 = 0.5;
    KP866025403 = sin(M_PI / 3.0); // approx 0.866025403

    ms = 1;
    mb = 1;
    me = N - 5; 

    cr = (R*)aligned_alloc(64, N * sizeof(R));
    ci = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, (N * 10) * sizeof(R));
    rs = (stride)aligned_alloc(64, N * sizeof(INT));

    for (INT i = 0; i < N; ++i) {
        cr[i] = (R)(i & 1 ? 1 : -1);
        ci[i] = (R)((i + 1) & 1 ? 0.5 : -0.5);
        rs[i] = (i < 6) ? i : rand() % (N - 1);
    }

    for (INT i = 0; i < N * 10; ++i) {
        W[i] = sin(i * 0.01) * cos(i * 0.02);
    }
}