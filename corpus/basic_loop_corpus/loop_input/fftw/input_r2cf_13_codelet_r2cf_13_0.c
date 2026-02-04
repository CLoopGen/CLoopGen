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

// Define all required constant coefficients
const E KP083333333 = 0.83333333;
const E KP075902986 = 0.75902986;
const E KP251768516 = 0.251768516;
const E KP503537032 = 0.503537032;
const E KP113854479 = 0.113854479;
const E KP265966249 = 0.265966249;
const E KP387390585 = 0.387390585;
const E KP300462606 = 0.300462606;
const E KP132983124 = 0.132983124;
const E KP258260390 = 0.258260390;
const E KP2_000000000 = 2.000000000;
const E KP1_732050807 = 1.732050807;
const E KP300238635 = 0.300238635;
const E KP011599105 = 0.011599105;
const E KP156891391 = 0.156891391;
const E KP256247671 = 0.256247671;
const E KP174138601 = 0.174138601;
const E KP575140729 = 0.575140729;
const E KP866025403 = 0.866025403;
const E KP500000000 = 0.500000000;

// Data pointers and sizes
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
    const size_t data_size_mb = 64; // Target ~64MB for reasonable timing (~0.01 sec on modern CPU)
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(R);
    
    // Allocate sufficient space to avoid out-of-bounds access
    R0 = aligned_alloc(64, sizeof(R) * total_elements);
    R1 = aligned_alloc(64, sizeof(R) * total_elements);
    Cr = aligned_alloc(64, sizeof(R) * total_elements);
    Ci = aligned_alloc(64, sizeof(R) * total_elements);

    rs = malloc(sizeof(INT) * 7);
    csr = malloc(sizeof(INT) * 7);
    csi = malloc(sizeof(INT) * 7);

    // Initialize strides: assume unit stride or small offsets
    for (int j = 0; j < 7; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    // Set vector length so that indexing stays within bounds
    // Ensure max index used in loop does not exceed array bounds
    // Maximum offset seen: rs[6], csr[6], csi[6], etc.
    // Also R1[(rs[5])], R0[(rs[3])], etc.
    v = total_elements / 16; // Heuristic: ensure enough room for offsets
    if (v > 1000000) v = 1000000; // Cap to avoid excessive iterations
    if (v < 1) v = 1;

    ivs = 1;
    ovs = 1;

    // Initialize input data to prevent NaN/inf issues
    for (size_t j = 0; j < total_elements; ++j) {
        R0[j] = sin(j & 511);
        R1[j] = cos(j & 511);
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}