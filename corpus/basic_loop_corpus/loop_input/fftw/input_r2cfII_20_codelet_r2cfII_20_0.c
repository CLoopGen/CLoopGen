#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Data size: aim for ~128MB of data to ensure loop runs ~0.01s on modern CPU
#define DATA_SIZE (16 * 1024 * 1024)  // 16M elements, each 8 bytes -> 128MB

R *R0;
R *R1;
R *Cr;
R *Ci;

stride rs;
stride csr;
stride csi;

INT v = 10000;  // Loop count per iteration set
INT ivs = 1;    // input stride step
INT ovs = 1;    // output stride step

E KP572061402 = 0.572061402;
E KP218508012 = 0.218508012;
E KP309016994 = 0.309016994;
E KP809016994 = 0.809016994;
E KP559016994 = 0.559016994;
E KP951056516 = 0.951056516;
E KP587785252 = 0.587785252;
E KP250000000 = 0.250000000;
E KP176776695 = 0.176776695;
E KP395284707 = 0.395284707;
E KP672498511 = 0.672498511;
E KP415626937 = 0.415626937;
E KP707106781 = 0.707106781;

INT i;

void init_vars() {
    // Allocate large arrays to dominate runtime and avoid out-of-bounds access
    R0 = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    R1 = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    Cr = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    Ci = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);

    // Initialize array contents to prevent NaN/inf that might affect timing
    for (INT j = 0; j < DATA_SIZE; ++j) {
        R0[j] = (R)(j % 1000) / 100.0;
        R1[j] = (R)((j + 50) % 1000) / 100.0;
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }

    // Allocate and initialize stride vectors
    // Need indices up to at least [9] safely accessed via rs[...]
    rs = (stride)aligned_alloc(64, sizeof(INT) * 10);
    csr = (stride)aligned_alloc(64, sizeof(INT) * 10);
    csi = (stride)aligned_alloc(64, sizeof(INT) * 10);

    // Set valid small strides; values must be positive and allow indexing within allocated data
    for (INT j = 0; j < 10; ++j) {
        rs[j] = (j * 1024) % (DATA_SIZE / 2);   // Ensure rs[x] doesn't cause overflow
        csr[j] = (j * 512) % (DATA_SIZE / 2);
        csi[j] = (j * 512) % (DATA_SIZE / 2);
    }
}