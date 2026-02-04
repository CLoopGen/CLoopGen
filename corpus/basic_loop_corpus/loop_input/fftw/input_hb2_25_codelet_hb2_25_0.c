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
E KP998026728 = 0.998026728;
E KP062790519 = 0.062790519;
E KP992114701 = 0.992114701;
E KP125333233 = 0.125333233;
E KP425779291 = 0.425779291;
E KP904827052 = 0.904827052;
E KP248689887 = 0.248689887;
E KP968583161 = 0.968583161;
E KP770513242 = 0.770513242;
E KP637423989 = 0.637423989;
E KP844327925 = 0.844327925;
E KP535826794 = 0.535826794;
E KP684547105 = 0.684547105;
E KP728968627 = 0.728968627;
E KP481753674 = 0.481753674;
E KP876306680 = 0.876306680;
E KP559016994 = 0.559016994;
E KP250000000 = 0.250000000;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
INT m;

void init_vars() {
    const INT N = 1 << 16;  // Adjusted for ~0.01s runtime: 65536 elements
    const INT vector_size = 25;

    cr = (R*)aligned_alloc(32, sizeof(R) * N * vector_size);
    ci = (R*)aligned_alloc(32, sizeof(R) * N * vector_size);
    W = (R*)aligned_alloc(32, sizeof(R) * N * 8);
    rs = (stride)aligned_alloc(32, sizeof(INT) * vector_size);

    for (INT i = 0; i < vector_size; ++i) {
        rs[i] = i * N;
    }

    mb = 1;
    me = N;
    ms = 1;

    for (INT i = mb; i < me; ++i) {
        R theta = 2.0 * M_PI * i / N;
        W[(i - (mb - 1)) * 8 + 0] = cos(0.0 * theta);
        W[(i - (mb - 1)) * 8 + 1] = sin(0.0 * theta);
        W[(i - (mb - 1)) * 8 + 2] = cos(1.0 * theta);
        W[(i - (mb - 1)) * 8 + 3] = sin(1.0 * theta);
        W[(i - (mb - 1)) * 8 + 4] = cos(2.0 * theta);
        W[(i - (mb - 1)) * 8 + 5] = sin(2.0 * theta);
        W[(i - (mb - 1)) * 8 + 6] = cos(3.0 * theta);
        W[(i - (mb - 1)) * 8 + 7] = sin(3.0 * theta);
    }

    for (INT i = 0; i < N * vector_size; ++i) {
        cr[i] = (R)(rand()) / RAND_MAX;
        ci[i] = (R)(rand()) / RAND_MAX;
    }
}