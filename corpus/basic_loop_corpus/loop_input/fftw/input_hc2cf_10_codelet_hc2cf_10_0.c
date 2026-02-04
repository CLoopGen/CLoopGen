#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

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

#define DATA_SIZE_MB 64
#define N (DATA_SIZE_MB * (1 << 17) / sizeof(R))  // Adjust so total data is ~64MB

static R *alloc_aligned_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 64, n * sizeof(R)) != 0) {
        exit(1);
    }
    return (R *)ptr;
}

void init_vars() {
    size_t i;

    Rp = alloc_aligned_array(N);
    Ip = alloc_aligned_array(N);
    Rm = alloc_aligned_array(N);
    Im = alloc_aligned_array(N);
    W = alloc_aligned_array(18 * (N + 1));  // W accessed up to index (mb-1)*18 + 18*(me-mb)+17

    rs = (INT *)malloc(sizeof(INT) * 5);
    if (!rs) exit(1);

    // Set strides: assume unit stride for indices 0..4
    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3; rs[4] = 4;

    // Initialize constants
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;

    // Set loop bounds
    mb = 1;
    me = (N / 5) - 1;  // Ensure we don't exceed array bounds via rs[4] indexing
    ms = 1;

    // Initialize arrays with non-zero values to avoid division by zero or no-op computations
    for (i = 0; i < N; i++) {
        Rp[i] = (R)(i + 1) * 0.1;
        Ip[i] = (R)(i + 1) * 0.2;
        Rm[i] = (R)(i + 1) * 0.3;
        Im[i] = (R)(i + 1) * 0.4;
    }

    for (i = 0; i < 18 * (me - mb + 2); i++) {
        W[i] = (R)(i % 18) * 0.01 + 1.0;
    }
}