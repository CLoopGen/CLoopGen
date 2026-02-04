#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP707106781;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~16MB of data (adjustable for timing)
    
    cr = (R*)aligned_alloc(64, sizeof(R) * N);
    ci = (R*)aligned_alloc(64, sizeof(R) * N);
    W = (R*)aligned_alloc(64, sizeof(R) * (N * 6)); // each iteration uses 6 elements

    rs = (stride)aligned_alloc(64, sizeof(INT) * 8);
    
    // Initialize rs stride values to safe offsets within array bounds
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;
    rs[4] = 4;
    rs[5] = 5;
    rs[6] = 6;
    rs[7] = 7;

    // Set loop parameters
    mb = 1;
    me = (N / 8) - 1;  // ensure all indexed accesses stay in bounds
    ms = 1;

    KP707106781 = 0.707106781; // typical constant for FFT scaling

    // Initialize arrays with non-zero values to avoid division by zero or no-op math
    for (size_t i = 0; i < N; i++) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }

    for (size_t i = 0; i < N * 6; i++) {
        W[i] = sin(i * 0.003) * 0.5 + 1.0;
    }
}