#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *Rp = NULL;
R *Ip = NULL;
R *Rm = NULL;
R *Im = NULL;
R *W = NULL;
stride rs = NULL;
INT mb = 0;
INT me = 0;
INT ms = 0;
INT m = 0;

void init_vars() {
    const size_t N = 1 << 20; // ~8MB per array, total ~40MB of data

    Rp = (R*)aligned_alloc(64, N * sizeof(R));
    Ip = (R*)aligned_alloc(64, N * sizeof(R));
    Rm = (R*)aligned_alloc(64, N * sizeof(R));
    Im = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, (N * 6) * sizeof(R)); // Each iteration uses 6 elements
    rs = (INT*)aligned_alloc(64, N * sizeof(INT));

    for (size_t i = 0; i < N; ++i) {
        Rp[i] = (R)(rand() % 1000) / 100.0;
        Ip[i] = (R)(rand() % 1000) / 100.0;
        Rm[i] = (R)(rand() % 1000) / 100.0;
        Im[i] = (R)(rand() % 1000) / 100.0;
        rs[i] = (rand() % 16) + 1; // small strides between 1 and 16
    }

    for (size_t i = 0; i < N * 6; ++i) {
        W[i] = (R)(rand() % 1000) / 100.0;
    }

    mb = 1;
    me = N - 2; // Ensure we don't go out of bounds when accessing rs[1] and W+6
    ms = 1;

    if (me <= mb) {
        me = mb + 1;
    }
}