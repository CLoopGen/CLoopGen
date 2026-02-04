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
R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
E KP500000000;
E KP866025403;
INT m;

void init_vars() {
    const size_t N = (1 << 20); // ~1M elements, adjust for ~0.01s runtime
    const INT vector_length = 15; // rs indices go up to 14 -> need at least 15 stride entries

    // Allocate data arrays with padding to prevent out-of-bounds access
    ri = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), N * 28 * sizeof(R)); // W accessed up to offset 27 per iteration
    rs = (INT*)aligned_alloc(sizeof(INT), vector_length * sizeof(INT));

    // Initialize constants
    KP587785252 = (E)0.587785252;
    KP951056516 = (E)0.951056516;
    KP250000000 = (E)0.250000000;
    KP559016994 = (E)0.559016994;
    KP500000000 = (E)0.500000000;
    KP866025403 = (E)0.866025403;

    // Set loop bounds
    mb = 0;
    me = N;
    ms = 1;

    // Initialize stride array: use unit stride for simplicity and safety
    for (INT i = 0; i < vector_length; i++) {
        rs[i] = i;
    }

    // Initialize input arrays with non-zero test values to allow meaningful computation
    for (size_t i = 0; i < N; i++) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
    }

    // Initialize twiddle factors W: each block of 28 values used per iteration
    for (size_t i = 0; i < N; i++) {
        for (int j = 0; j < 28; j++) {
            W[i * 28 + j] = sin((i + j) * 0.005);
        }
    }
}