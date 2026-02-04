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
E KP250000000;
E KP500000000;
E KP433012701;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~8MB per array, suitable for ~0.01s runtime

    Rp = (R*)aligned_alloc(64, N * sizeof(R));
    Ip = (R*)aligned_alloc(64, N * sizeof(R));
    Rm = (R*)aligned_alloc(64, N * sizeof(R));
    Im = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, (N * 10) * sizeof(R)); // W is indexed with offset up to (mb-1)*10 + 10*(me-mb), so ensure enough space
    rs = (INT*)aligned_alloc(64, 3 * sizeof(INT));

    for (size_t i = 0; i < N; i++) {
        Rp[i] = (R)(i % 1234);
        Ip[i] = (R)(i % 5678);
        Rm[i] = (R)(i % 9012);
        Im[i] = (R)(i % 3456);
    }

    for (size_t i = 0; i < N * 10; i++) {
        W[i] = (R)(1.0 + (i % 1000)) / 1000.0;
    }

    for (int i = 0; i < 3; i++) {
        rs[i] = i + 1;
    }

    KP250000000 = 0.25;
    KP500000000 = 0.5;
    KP433012701 = 0.433012701;

    mb = 1;
    me = N - 1;
    ms = 1;

    m = mb;
}