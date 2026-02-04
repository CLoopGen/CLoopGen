#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Define data size to target ~0.01s runtime (approx 64M elements for typical CPU)
static const INT DATA_SIZE = 64 << 20; // 64 million elements

// Allocate large arrays to ensure meaningful computation duration
R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;

// Stride arrays: each has 5 elements to support index access like csr[3], csi[4], etc.
stride rs = NULL;
stride csr = NULL;
stride csi = NULL;

// Scalar parameters
INT v = 0;
INT ivs = 1;
INT ovs = 1;

E KP984807753 = 0.984807753;
E KP173648177 = 0.173648177;
E KP300767466 = 0.300767466;
E KP1_705737063 = 1.705737063;
E KP642787609 = 0.642787609;
E KP766044443 = 0.766044443;
E KP1_326827896 = 1.326827896;
E KP1_113340798 = 1.113340798;
E KP500000000 = 0.500000000;
E KP866025403 = 0.866025403;
E KP2_000000000 = 2.000000000;
E KP1_732050807 = 1.732050807;

INT i = 0;

void init_vars() {
    // Allocate arrays with sufficient size
    R0 = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    R1 = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    Cr = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    Ci = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));

    rs = (stride)malloc(5 * sizeof(INT));
    csr = (stride)malloc(5 * sizeof(INT));
    csi = (stride)malloc(5 * sizeof(INT));

    // Initialize stride arrays to valid small offsets
    for (int idx = 0; idx < 5; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx;
        csi[idx] = idx;
    }

    // Set loop count so that we don't exceed array bounds
    // The maximum index used is [csi[4]], [csr[4]], and [rs[4]] => offset up to 4
    // We need at least v iterations, each advancing Cr, Ci by ivs, R0/R1 by ovs
    // To be safe, let v = DATA_SIZE / 8 (conservative estimate)
    v = DATA_SIZE / 8;

    // Initialize array elements to prevent NaN/undefined behavior
    for (INT j = 0; j < DATA_SIZE; ++j) {
        R0[j] = 0.1 * j;
        R1[j] = 0.2 * j;
        Cr[j] = 0.01 * (j % 1000);
        Ci[j] = 0.02 * (j % 1000);
    }
}