#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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
E KP998026728 = 0.998026728;
E KP062790519 = 0.062790519;
E KP684547105 = 0.684547105;
E KP728968627 = 0.728968627;
E KP481753674 = 0.481753674;
E KP876306680 = 0.876306680;
E KP248689887 = 0.248689887;
E KP968583161 = 0.968583161;
E KP992114701 = 0.992114701;
E KP125333233 = 0.125333233;
E KP425779291 = 0.425779291;
E KP904827052 = 0.904827052;
E KP637423989 = 0.637423989;
E KP770513242 = 0.770513242;
E KP844327925 = 0.844327925;
E KP535826794 = 0.535826794;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP250000000 = 0.250000000;
E KP559016994 = 0.559016994;

INT m;

static const int DATA_SIZE = 1 << 20; // ~16MB total data (adjustable)
static const int W_SIZE = 50;
static const int MAX_RS = 25;

void init_vars() {
    cr = (R*)aligned_alloc(32, sizeof(R) * DATA_SIZE);
    ci = (R*)aligned_alloc(32, sizeof(R) * DATA_SIZE);
    W = (R*)aligned_alloc(32, sizeof(R) * W_SIZE * DATA_SIZE);
    rs = (INT*)aligned_alloc(32, sizeof(INT) * MAX_RS);

    for (int i = 0; i < DATA_SIZE; ++i) {
        cr[i] = (R)(i % 100) * 0.01;
        ci[i] = (R)((i + 10) % 100) * 0.01;
    }

    for (int i = 0; i < W_SIZE * DATA_SIZE; ++i) {
        W[i] = (R)(i % 1000) * 0.001;
    }

    for (int i = 0; i < MAX_RS; ++i) {
        rs[i] = (i + 1) * 2 - 1;
    }

    mb = 1;
    me = 10000;
    ms = 1;
}