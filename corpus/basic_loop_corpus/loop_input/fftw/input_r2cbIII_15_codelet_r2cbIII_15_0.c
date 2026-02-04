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

R *R0;
R *R1;
R *Cr;
R *Ci;

stride rs;
stride csr;
stride csi;

INT v;
INT ivs;
INT ovs;

E KP1_732050807 = 1.732050807;
E KP433012701 = 0.433012701;
E KP968245836 = 0.968245836;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP250000000 = 0.250000000;
E KP1_647278207 = 1.647278207;
E KP1_018073920 = 1.018073920;
E KP559016994 = 0.559016994;
E KP500000000 = 0.500000000;
E KP2_000000000 = 2.000000000;
E KP1_118033988 = 1.118033988;
E KP1_175570504 = 1.175570504;
E KP1_902113032 = 1.902113032;

INT i;

void init_vars() {
    const size_t data_size = 1 << 22; // ~16MB of complex data (each R is 8 bytes)
    const INT N = 8; // implied by indexing up to csr[7], csi[7], rs[7]

    // Allocate aligned memory for safety and performance
    Cr = aligned_alloc(64, data_size * sizeof(R));
    Ci = aligned_alloc(64, data_size * sizeof(R));
    R0 = aligned_alloc(64, data_size * sizeof(R));
    R1 = aligned_alloc(64, data_size * sizeof(R));

    rs = malloc(N * sizeof(INT));
    csr = malloc(N * sizeof(INT));
    csi = malloc(N * sizeof(INT));

    // Initialize strides: assume unit stride for simplicity and correctness
    for (INT idx = 0; idx < N; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    // Set vector length so that we don't go out of bounds
    // Each iteration accesses indices [0,1,2,3,4,5,6,7] -> need at least 8 elements
    // Ensure total access within data_size
    v = data_size / N;  // Number of vector groups

    ivs = N; // input stride step (per vector)
    ovs = N; // output stride step (per vector)

    // Initialize Cr and Ci with non-zero test data to avoid degenerate math
    for (size_t j = 0; j < data_size; ++j) {
        Cr[j] = sin(j * 0.01);
        Ci[j] = cos(j * 0.01);
    }

    // Initialize R0 and R1 to zero
    memset(R0, 0, data_size * sizeof(R));
    memset(R1, 0, data_size * sizeof(R));
}