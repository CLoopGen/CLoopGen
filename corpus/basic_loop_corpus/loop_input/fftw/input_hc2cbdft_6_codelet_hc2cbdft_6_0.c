#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
E KP500000000 = 0.5;
E KP866025403 = 0.866025403;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~16MB of data: sufficient for ~0.01s runtime on modern CPU

    Rp = (R*)aligned_alloc(32, N * sizeof(R));
    Ip = (R*)aligned_alloc(32, N * sizeof(R));
    Rm = (R*)aligned_alloc(32, N * sizeof(R));
    Im = (R*)aligned_alloc(32, N * sizeof(R));
    W = (R*)aligned_alloc(32, 10 * ((N + 1) / 2) * sizeof(R));
    rs = (INT*)aligned_alloc(32, 3 * sizeof(INT));

    for (size_t i = 0; i < N; ++i) {
        Rp[i] = (R)(i % 100) * 0.1;
        Ip[i] = (R)((i + 1) % 100) * 0.1;
        Rm[i] = (R)((i + 2) % 100) * 0.1;
        Im[i] = (R)((i + 3) % 100) * 0.1;
    }

    for (size_t i = 0; i < 10 * ((N + 1) / 2); ++i) {
        W[i] = (R)(i % 10) * 0.1 + 1.0;
    }

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;

    ms = 1;
    mb = 1;
    me = (N / 2);
}