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

static R *alloc_aligned_r(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 64, sizeof(R) * n) != 0) {
        exit(1);
    }
    return (R*)ptr;
}

static INT *alloc_aligned_int(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 64, sizeof(INT) * n) != 0) {
        exit(1);
    }
    return (INT*)ptr;
}

void init_vars() {
    const size_t N = 1 << 20; // ~8MB per array, total ~40MB

    Rp = alloc_aligned_r(N);
    Ip = alloc_aligned_r(N);
    Rm = alloc_aligned_r(N);
    Im = alloc_aligned_r(N);
    W = alloc_aligned_r(6 + 6 * (N - 1)); // Each iteration uses W[0..5], and we access up to me-1

    rs = alloc_aligned_int(2);
    rs[0] = 0;
    rs[1] = 1; // used as offset: rs[1] must be valid

    ms = 1;
    mb = 1;
    me = N - 1; // Ensure m < me stays in bounds for all arrays with stride ms and rs[1]=1

    for (size_t i = 0; i < N; ++i) {
        Rp[i] = (R)(i + 1);
        Ip[i] = (R)(i + 2);
        Rm[i] = (R)(i + 3);
        Im[i] = (R)(i + 4);
    }

    for (size_t i = 0; i < 6 + 6 * (N - 1); ++i) {
        W[i] = (R)(1.0 + (i % 6));
    }
}