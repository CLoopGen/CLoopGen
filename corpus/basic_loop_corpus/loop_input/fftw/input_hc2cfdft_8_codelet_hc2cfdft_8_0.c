#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP353553390;
E KP500000000;
INT m;

#define N (1 << 20)
#define W_SIZE (14 * (N + 1))

void init_vars() {
    KP353553390 = 0.353553390;
    KP500000000 = 0.500000000;

    mb = 1;
    me = N;
    ms = 1;

    rs = (stride)aligned_alloc(64, sizeof(INT) * 4);
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    Rp = (R*)aligned_alloc(64, sizeof(R) * N * 4);
    Ip = (R*)aligned_alloc(64, sizeof(R) * N * 4);
    Rm = (R*)aligned_alloc(64, sizeof(R) * N * 4);
    Im = (R*)aligned_alloc(64, sizeof(R) * N * 4);
    W = (R*)aligned_alloc(64, sizeof(R) * W_SIZE);

    for (INT i = 0; i < N * 4; i++) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    for (INT i = 0; i < W_SIZE; i++) {
        W[i] = sin(i * 0.001) * 0.9 + 0.1;
    }
}