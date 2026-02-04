#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Precomputed constants to avoid runtime initialization issues
static const E KP250000000_val = 0.25;
static const E KP559016994_val = 0.587785252;
static const E KP587785252_val = 0.951056516;
static const E KP951056516_val = 0.951056516;

E KP250000000 = 0.0;
E KP559016994 = 0.0;
E KP587785252 = 0.0;
E KP951056516 = 0.0;

R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;
stride rs = NULL;
stride csr = NULL;
stride csi = NULL;
INT v = 0;
INT ivs = 0;
INT ovs = 0;
INT i = 0;

void init_vars() {
    // Set constants using runtime initialization to avoid compile-time expression errors
    KP250000000 = KP250000000_val;
    KP559016994 = KP559016994_val;
    KP587785252 = KP587785252_val;
    KP951056516 = KP951056516_val;

    // Define data size: aim for ~64M elements total to ensure loop runs ~0.01 sec on modern CPU
    const INT N = 1 << 23; // ~8MB per array, total ~64MB of data

    // Allocate aligned memory to prevent cache-line issues and allow vectorization
    R0 = (R*)aligned_alloc(64, sizeof(R) * N);
    R1 = (R*)aligned_alloc(64, sizeof(R) * N);
    Cr = (R*)aligned_alloc(64, sizeof(R) * N);
    Ci = (R*)aligned_alloc(64, sizeof(R) * N);

    rs = (stride)aligned_alloc(64, sizeof(INT) * 10);
    csr = (stride)aligned_alloc(64, sizeof(INT) * 11);
    csi = (stride)aligned_alloc(64, sizeof(INT) * 11);

    // Initialize stride arrays: assume access patterns with offsets [0..9] for rs, [0..10] for csr/csi
    for (INT j = 0; j < 10; ++j) {
        rs[j] = j * (N / 10);
    }
    for (INT j = 0; j < 11; ++j) {
        csr[j] = j * (N / 11);
        csi[j] = j * (N / 11);
    }

    // Set input strides
    ivs = 1;
    ovs = 1;

    // Initialize v: number of iterations
    v = N / 10; // ensures we don't exceed bounds given rs[9] offset

    // Initialize input arrays with non-zero test values to allow observable computation
    for (INT j = 0; j < N; ++j) {
        R0[j] = sin(j * 0.01);
        R1[j] = cos(j * 0.01);
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}