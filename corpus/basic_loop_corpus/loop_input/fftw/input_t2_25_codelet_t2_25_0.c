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

void init_vars() {
    const size_t N = 1 << 20; // ~16MB total data, should run in ~0.01s with optimization
    const INT vec_length = 25; // max index used: rs[24] -> need 25 elements

    ri = (R*)aligned_alloc(64, N * sizeof(R));
    ii = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, N * 8 * sizeof(R)); // W accessed up to offset 8*(me-1)+7
    rs = (INT*)aligned_alloc(64, vec_length * sizeof(INT));

    if (!ri || !ii || !W || !rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data arrays with non-zero values for meaningful computation
    for (size_t i = 0; i < N; i++) {
        ri[i] = (R)(i + 1) * 0.001;
        ii[i] = (R)(i + 1) * 0.002;
    }
    for (size_t i = 0; i < N * 8; i++) {
        W[i] = (R)(i % 1000) * 0.001;
    }

    // Initialize stride array: use unit strides for simplicity
    for (INT i = 0; i < vec_length; i++) {
        rs[i] = i;
    }

    // Set loop bounds to ensure no out-of-bounds access:
    // - m from mb to me-1
    // - W accessed at [0..7], so we require me <= N
    // - ri[ii][rs[k]] must be valid: rs[k] < N, and base pointer + ms*(me-mb-1) must be valid
    mb = 0;
    me = N / 2;  // leave room for stride offsets
    ms = 1;

    // Ensure that the maximum index accessed via rs is within bounds
    INT max_offset = 0;
    for (INT i = 0; i < vec_length; i++) {
        if (rs[i] > max_offset) max_offset = rs[i];
    }
    if (me + max_offset >= N) {
        me = N - max_offset - 1;
    }
}