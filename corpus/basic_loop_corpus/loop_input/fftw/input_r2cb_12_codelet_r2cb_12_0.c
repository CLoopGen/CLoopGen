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
E KP1_732050807;
E KP2_000000000;
INT i;

#define DATA_SIZE (64 << 10)  // 64K elements per array, sufficient for ~0.01 sec runtime

static void init_arrays() {
    R0 = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    R1 = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    Cr = (R*)aligned_alloc(32, 8 * sizeof(R));
    Ci = (R*)aligned_alloc(32, 8 * sizeof(R));
    rs = (stride)aligned_alloc(32, 8 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 8 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 8 * sizeof(INT));

    if (!R0 || !R1 || !Cr || !Ci || !rs || !csr || !csi) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize Cr and Ci with dummy values
    for (int j = 0; j < 8; ++j) {
        Cr[j] = sin(j + 1);
        Ci[j] = cos(j + 1);
    }

    // Set strides: assume unit stride for simplicity
    for (int j = 0; j < 8; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    // Initialize output arrays to zero
    memset(R0, 0, DATA_SIZE * sizeof(R));
    memset(R1, 0, DATA_SIZE * sizeof(R));
}

void init_vars() {
    KP1_732050807 = 1.732050807;
    KP2_000000000 = 2.0;
    ivs = 1;
    ovs = 1;
    v = DATA_SIZE / 8;  // Ensure we don't exceed array bounds in loop

    init_arrays();
}