#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
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
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
INT m;

void init_vars() {
    const INT N = 32768;  // Adjusted for ~0.01s runtime with this complex loop
    const INT alignment = 64;

    mb = 1;
    me = N + 1;
    ms = 1;

    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;

    rs = aligned_alloc(alignment, 10 * sizeof(INT));
    for (INT i = 0; i < 10; i++) {
        rs[i] = i * 1;
    }

    Rp = aligned_alloc(alignment, (N + 10) * sizeof(R));
    Ip = aligned_alloc(alignment, (N + 10) * sizeof(R));
    Rm = aligned_alloc(alignment, (N + 10) * sizeof(R));
    Im = aligned_alloc(alignment, (N + 10) * sizeof(R));
    W = aligned_alloc(alignment, (me - mb + 1) * 8 * sizeof(R));

    for (INT i = 0; i < N + 10; i++) {
        Rp[i] = (R)(rand() % 1000) / 100.0;
        Ip[i] = (R)(rand() % 1000) / 100.0;
        Rm[i] = (R)(rand() % 1000) / 100.0;
        Im[i] = (R)(rand() % 1000) / 100.0;
    }

    for (INT i = 0; i < (me - mb + 1) * 8; i++) {
        W[i] = (R)(rand() % 1000) / 100.0;
    }
}