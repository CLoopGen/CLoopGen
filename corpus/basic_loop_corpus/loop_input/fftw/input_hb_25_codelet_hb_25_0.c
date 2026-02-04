#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
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
E KP998026728;
E KP062790519;
E KP992114701;
E KP125333233;
E KP425779291;
E KP904827052;
E KP248689887;
E KP968583161;
E KP770513242;
E KP637423989;
E KP844327925;
E KP535826794;
E KP684547105;
E KP728968627;
E KP481753674;
E KP876306680;
E KP559016994;
E KP250000000;
E KP587785252;
E KP951056516;
INT m;

void init_vars() {
    const size_t N = 1 << 20;
    const INT vector_length = 25;
    const INT W_size_per_iter = 48;
    const INT total_iters = 10000;

    cr = (R*)aligned_alloc(32, N * sizeof(R));
    ci = (R*)aligned_alloc(32, N * sizeof(R));
    W = (R*)aligned_alloc(32, (total_iters * W_size_per_iter) * sizeof(R));
    rs = (INT*)aligned_alloc(32, vector_length * sizeof(INT));

    for (size_t i = 0; i < N; i++) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }
    for (int i = 0; i < vector_length; i++) {
        rs[i] = i;
    }
    for (size_t i = 0; i < total_iters * W_size_per_iter; i++) {
        W[i] = sin(i * 0.001);
    }

    mb = 1;
    me = total_iters + 1;
    ms = 1;

    KP998026728 = 0.998026728;
    KP062790519 = 0.062790519;
    KP992114701 = 0.992114701;
    KP125333233 = 0.125333233;
    KP425779291 = 0.425779291;
    KP904827052 = 0.904827052;
    KP248689887 = 0.248689887;
    KP968583161 = 0.968583161;
    KP770513242 = 0.770513242;
    KP637423989 = 0.637423989;
    KP844327925 = 0.844327925;
    KP535826794 = 0.535826794;
    KP684547105 = 0.684547105;
    KP728968627 = 0.728968627;
    KP481753674 = 0.481753674;
    KP876306680 = 0.876306680;
    KP559016994 = 0.559016994;
    KP250000000 = 0.250000000;
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
}