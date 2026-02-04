#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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
E KP998026728 = 0.998026728;
E KP062790519 = 0.062790519;
E KP425779291 = 0.425779291;
E KP904827052 = 0.904827052;
E KP992114701 = 0.992114701;
E KP125333233 = 0.125333233;
E KP637423989 = 0.637423989;
E KP770513242 = 0.770513242;
E KP684547105 = 0.684547105;
E KP728968627 = 0.728968627;
E KP481753674 = 0.481753674;
E KP876306680 = 0.876306680;
E KP844327925 = 0.844327925;
E KP535826794 = 0.535826794;
E KP248689887 = 0.248689887;
E KP968583161 = 0.968583161;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP250000000 = 0.250000000;
E KP559016994 = 0.559016994;
INT m;

static R *alloc_aligned_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(R)) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (R*)ptr;
}

void init_vars() {
    const INT total_size = 1 << 20;
    const INT stride_size = 25;
    const INT w_size = (total_size / 48) * 48 + 48;

    ri = alloc_aligned_array(total_size);
    ii = alloc_aligned_array(total_size);
    W = alloc_aligned_array(w_size);
    rs = malloc(stride_size * sizeof(INT));

    for (INT i = 0; i < total_size; ++i) {
        ri[i] = (R)(i % 1000) * 0.01;
        ii[i] = (R)((i + 1) % 1000) * 0.01;
    }

    for (INT i = 0; i < w_size; ++i) {
        W[i] = (R)(i % 50) * 0.02;
    }

    for (INT i = 0; i < stride_size; ++i) {
        rs[i] = (i + 1) * 4;
    }

    mb = 0;
    me = w_size / 48;
    ms = 4;
}