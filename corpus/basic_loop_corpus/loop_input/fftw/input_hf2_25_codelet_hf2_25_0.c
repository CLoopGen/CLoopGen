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
E KP250000000 = 0.25;
E KP559016994 = 0.559016994;

INT m;

void init_vars() {
    const size_t N = (1 << 20); // ~8MB for each array (double), total ~24MB
    const INT vector_size = 25; // rs indices go up to 24

    cr = (R*)aligned_alloc(32, N * sizeof(R));
    ci = (R*)aligned_alloc(32, N * sizeof(R));
    W = (R*)aligned_alloc(32, N * 8 * sizeof(R)); // W accessed with +8 stride per loop

    rs = (INT*)aligned_alloc(32, vector_size * sizeof(INT));
    for (INT i = 0; i < vector_size; i++) {
        rs[i] = i * 1001 % (N / 8); // ensure moderate strides within bounds
    }

    // Initialize data arrays to prevent NaN/Inf and make computation stable
    for (size_t i = 0; i < N; i++) {
        cr[i] = sin(i * 0.001);
        ci[i] = cos(i * 0.001);
    }
    for (size_t i = 0; i < N * 8; i++) {
        W[i] = sin(i * 0.01) * 0.5 + 0.5;
    }

    // Loop bounds setup: ensure W indexing stays in bounds
    mb = 1;
    me = mb + (N / 100); // Adjust so that W + ((me - mb) * 8) < original allocated W size
    if (me > mb + (N * 8 - 8) / 8) me = mb + (N * 8 - 8) / 8;
    ms = 1;
}