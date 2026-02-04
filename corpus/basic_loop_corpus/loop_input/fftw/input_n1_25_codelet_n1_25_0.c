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
R *ro;
R *io;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
E KP425779291;
E KP904827052;
E KP637423989;
E KP770513242;
E KP998026728;
E KP062790519;
E KP992114701;
E KP125333233;
E KP684547105;
E KP728968627;
E KP481753674;
E KP876306680;
E KP844327925;
E KP535826794;
E KP248689887;
E KP968583161;
E KP250000000;
E KP559016994;
E KP587785252;
E KP951056516;
INT i;

void init_vars() {
    const INT N = 25; 
    const INT vector_size = (1 << 20) / sizeof(R); 

    v = vector_size;
    ivs = 1;
    ovs = 1;

    ri = (R*)aligned_alloc(64, sizeof(R) * v * N);
    ii = (R*)aligned_alloc(64, sizeof(R) * v * N);
    ro = (R*)aligned_alloc(64, sizeof(R) * v * N);
    io = (R*)aligned_alloc(64, sizeof(R) * v * N);
    is = (INT*)aligned_alloc(64, sizeof(INT) * N);
    os = (INT*)aligned_alloc(64, sizeof(INT) * N);

    for (INT idx = 0; idx < N; ++idx) {
        is[idx] = idx * v;
        os[idx] = idx * v;
    }

    for (INT vec = 0; vec < v * N; ++vec) {
        ri[vec] = (R)(rand() % 1000) / 100.0;
        ii[vec] = (R)(rand() % 1000) / 100.0;
        ro[vec] = 0.0;
        io[vec] = 0.0;
    }

    KP425779291 = 0.425779291;
    KP904827052 = 0.904827052;
    KP637423989 = 0.637423989;
    KP770513242 = 0.770513242;
    KP998026728 = 0.998026728;
    KP062790519 = 0.062790519;
    KP992114701 = 0.992114701;
    KP125333233 = 0.125333233;
    KP684547105 = 0.684547105;
    KP728968627 = 0.728968627;
    KP481753674 = 0.481753674;
    KP876306680 = 0.876306680;
    KP844327925 = 0.844327925;
    KP535826794 = 0.535826794;
    KP248689887 = 0.248689887;
    KP968583161 = 0.968583161;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
}