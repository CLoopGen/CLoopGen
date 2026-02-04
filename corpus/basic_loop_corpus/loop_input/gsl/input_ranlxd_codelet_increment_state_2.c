#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (1 << 20)  // 1MB of data

int next[12];
double one_bit;
int k;
int kmax;
double _usr_y1;
double y2;
double *xdbl;
double carry;
unsigned int ir;
unsigned int jr;

void init_vars() {
    // Initialize scalar variables
    one_bit = 1.0;
    k = 0;
    carry = 0.0;
    _usr_y1 = 0.0;
    y2 = 0.0;

    // Allocate and initialize xdbl array with size DATA_SIZE
    xdbl = (double*)aligned_alloc(sizeof(double), DATA_SIZE * sizeof(double));
    for (int i = 0; i < DATA_SIZE; ++i) {
        xdbl[i] = (double)(i % 1000) / 100.0;
    }

    // Initialize next array as a circular linked list of 12 nodes
    for (int i = 0; i < 11; ++i) {
        next[i] = i + 1;
    }
    next[11] = 0;  // wrap around

    // Set initial indices within bounds
    ir = 0;
    jr = 1;

    // Set kmax to ensure loop runs long enough (~0.01 sec)
    // Empirical tuning: assume ~10^8 operations/sec, so ~1e6 iterations ≈ 0.01 sec
    kmax = 1000000;

    // Ensure ir and jr stay in valid range during loop execution
    // Since next[] cycles through 0..11, ir and jr will remain in [0,11]
    // xdbl is accessed via ir and jr, so we must map them into valid xdbl range
    // Remap logical indices: use modulo to keep within xdbl bounds
    // But the code uses ir/jr directly as index -> must be < DATA_SIZE
    // Therefore, adjust initialization: make sure ir, jr are valid indices

    // Re-initialize ir and jr to safe values within [0, DATA_SIZE)
    ir = 13;
    jr = 14;

    // Ensure that during all k iterations, ir and jr updated via next[]
    // But next[] only has 12 entries — this suggests ir and jr are indices into next[]?
    // However, they are used to index xdbl[] which is large.

    // Contradiction in usage: next[] has 12 elements but xdbl is large.
    // Most plausible interpretation: ir and jr are indices into xdbl,
    // and next[] is used to update them, but next[] must contain valid indices into xdbl.

    // So rework: next[i] should give next index in xdbl array.
    // We'll set up a cycle within first 12 elements of xdbl.

    for (int i = 0; i < 11; ++i) {
        next[i] = i + 1;
    }
    next[11] = 0;

    // Now restrict ir and jr to [0,11] so they index both next[] and xdbl safely
    ir = 5;
    jr = 7;

    // And limit kmax to avoid issues, since cycle length is short
    kmax = 1000000;  // still many iterations over the cycle
}