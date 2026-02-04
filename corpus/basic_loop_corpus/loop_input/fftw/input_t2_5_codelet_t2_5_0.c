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

R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP250000000;
E KP559016994;
E KP587785252;
E KP951056516;
INT m;

void init_vars() {
    const INT N = 1 << 20; // ~16.8 million complex elements, suitable for ~0.01s runtime

    ri = (R*)aligned_alloc(32, sizeof(R) * N * 5);
    ii = (R*)aligned_alloc(32, sizeof(R) * N * 5);
    W = (R*)aligned_alloc(32, sizeof(R) * N * 4);

    rs = (stride)aligned_alloc(32, sizeof(INT) * 5);
    rs[0] = 0;
    rs[1] = 1 * N;
    rs[2] = 2 * N;
    rs[3] = 3 * N;
    rs[4] = 4 * N;

    KP250000000 = 0.25;
    KP559016994 = sin(M_PI * 0.1);
    KP587785252 = sin(M_PI * 0.375);
    KP951056516 = sin(M_PI * 0.25) + sin(M_PI * 0.125);

    mb = 0;
    me = N;
    ms = 1;

    for (INT i = 0; i < N; ++i) {
        ri[i] = drand48();
        ii[i] = drand48();
        for (INT j = 1; j <= 4; ++j) {
            ri[rs[j] + i] = drand48();
            ii[rs[j] + i] = drand48();
        }
        W[i*4+0] = cos(2*M_PI*i/N);
        W[i*4+1] = sin(2*M_PI*i/N);
        W[i*4+2] = cos(4*M_PI*i/N);
        W[i*4+3] = sin(4*M_PI*i/N);
    }
}