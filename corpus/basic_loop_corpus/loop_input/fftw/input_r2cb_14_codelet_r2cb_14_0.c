#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Allocate sufficient data to make loop run ~0.01s (aim for ~64M elements)
static const INT DATA_SIZE = 67108864; // 2^26, leads to about 0.01s runtime

// Declare arrays with proper sizes
R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;

// Stride arrays - each must have at least 8 entries (indexed up to 7 in loop)
stride rs = NULL;
stride csr = NULL;
stride csi = NULL;

// Scalar constants used in computation
E KP1_801937735 = 1.801937735;
E KP445041867   = 0.445041867;
E KP1_246979603 = 1.246979603;
E KP867767478   = 0.867767478;
E KP1_949855824 = 1.949855824;
E KP1_563662964 = 1.563662964;
E KP2_000000000 = 2.000000000;

// Loop control variables
INT v = 0;
INT ivs = 1;
INT ovs = 1;
INT i = 0;

void init_vars() {
    // Allocate large arrays to ensure meaningful runtime
    R0 = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));
    R1 = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));
    Cr = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));
    Ci = (R*)aligned_alloc(64, DATA_SIZE * sizeof(R));

    rs  = (stride)aligned_alloc(64, 8 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 8 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 8 * sizeof(INT));

    // Initialize stride index arrays to safe offsets within array bounds
    for (int idx = 0; idx < 8; idx++) {
        rs[idx]  = idx * ovs;
        csr[idx] = idx * ivs;
        csi[idx] = idx * ivs;
    }

    // Set loop count so that we don't exceed array bounds
    // Maximum index used: csr[7] -> 7*ivs offset into Cr/Ci, which has size DATA_SIZE
    // So we require: v * ivs + 7*ivs < DATA_SIZE  => v < DATA_SIZE - 7
    // Similarly for output: rs[6] used -> max offset 6*ovs per iteration
    // We require: v * ovs + 6*ovs < DATA_SIZE
    // Choose v conservatively
    v = (DATA_SIZE - 8) / 8;  // ensures we stay safely within bounds

    // Initialize input data to avoid NaN/Inf and allow stable computation
    for (INT j = 0; j < DATA_SIZE; ++j) {
        Cr[j] = (R)(j % 1000) * 0.01;
        Ci[j] = (R)((j + 100) % 999) * 0.01;
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}