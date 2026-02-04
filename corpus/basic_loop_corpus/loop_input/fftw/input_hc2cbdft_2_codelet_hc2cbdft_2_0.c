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
    const size_t N = (1 << 20); // ~8MB per array, total ~40MB, sufficient for ~0.01s runtime

    Rp = (R*)aligned_alloc(32, N * sizeof(R));
    Ip = (R*)aligned_alloc(32, N * sizeof(R));
    Rm = (R*)aligned_alloc(32, N * sizeof(R));
    Im = (R*)aligned_alloc(32, N * sizeof(R));
    W  = (R*)aligned_alloc(32, (N + 2) * sizeof(R)); // extra space for offset indexing
    rs = (stride)malloc(sizeof(INT));

    for (size_t i = 0; i < N; ++i) {
        Rp[i] = (R)(rand()) / RAND_MAX;
        Ip[i] = (R)(rand()) / RAND_MAX;
        Rm[i] = (R)(rand()) / RAND_MAX;
        Im[i] = (R)(rand()) / RAND_MAX;
    }

    for (size_t i = 0; i < N + 2; ++i) {
        W[i] = (R)(rand()) / RAND_MAX;
    }

    mb = 1;
    me = N - 1;
    ms = 1;
    *rs = 0;
}