#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Data size: aim for ~100ms runtime; original loop runs 'v' iterations
// Each iteration processes fixed-size strided access (size 10 implied by csr[9], csi[9], rs[9])
// We'll allocate arrays with at least 10 elements, and set v to control loop count.
// To achieve ~0.01s runtime, assume each iteration takes ~10ns -> use v = 1e6 to 1e7

#define ARRAY_SIZE 10000000ULL  // 10M elements per array
#define V_VALUE    1000000      // Loop runs 1M times

R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;
stride rs = NULL;
stride csr = NULL;
stride csi = NULL;
INT v = V_VALUE;
INT ivs = 1;  // input stride step
INT ovs = 1;  // output stride step

E KP1_414213562 = 1.414213562;
E KP2_000000000 = 2.000000000;
E KP250000000 = 0.250000000;
E KP951056516 = 0.951056516;
E KP587785252 = 0.587785252;
E KP559016994 = 0.559016994;

INT i;

void init_vars() {
    // Allocate large arrays to ensure measurable runtime
    Cr = (R*)aligned_alloc(64, ARRAY_SIZE * sizeof(R));
    Ci = (R*)aligned_alloc(64, ARRAY_SIZE * sizeof(R));
    R0 = (R*)aligned_alloc(64, ARRAY_SIZE * sizeof(R));
    R1 = (R*)aligned_alloc(64, ARRAY_SIZE * sizeof(R));

    if (!Cr || !Ci || !R0 || !R1) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data with non-zero values to avoid compiler optimizing away computations
    for (INT j = 0; j < ARRAY_SIZE; ++j) {
        Cr[j] = sin(j * 0.01);
        Ci[j] = cos(j * 0.01);
        R0[j] = 0.0;
        R1[j] = 0.0;
    }

    // Allocate and initialize stride vectors
    rs = (stride)malloc(10 * sizeof(INT));
    csr = (stride)malloc(10 * sizeof(INT));
    csi = (stride)malloc(10 * sizeof(INT));

    if (!rs || !csr || !csi) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    // Set valid strides (non-zero, within bounds)
    for (int j = 0; j < 10; ++j) {
        rs[j] = j * ovs;
        csr[j] = j * ivs;
        csi[j] = j * ivs;
    }

    // Ensure that during the loop:
    // i goes from v down to 1, stepping by 1
    // R0, R1 increment by ovs each time
    // Cr, Ci increment by ivs each time
    // So maximum index used: csr[9] at Cr + (v-1)*ivs => index = (v-1)*ivs + 9*ivs = v*ivs + 8*ivs
    // We require: v * ivs + 9 * ivs < ARRAY_SIZE
    // With v = 1e6, ivs = 1 -> max index ~1e6+9, so ARRAY_SIZE=10e6 is safe

    // Reset global loop counter
    i = v;
}