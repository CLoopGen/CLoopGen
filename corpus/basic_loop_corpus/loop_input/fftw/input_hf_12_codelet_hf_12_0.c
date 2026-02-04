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
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2
INT m;

void init_vars() {
    const INT N = 1 << 18; // ~256K elements, suitable for ~0.01 sec on modern CPU

    cr = (R*)aligned_alloc(64, sizeof(R) * N);
    ci = (R*)aligned_alloc(64, sizeof(R) * N);
    W = (R*)aligned_alloc(64, sizeof(R) * 22 * N); // W has 22 entries per iteration
    rs = (stride)aligned_alloc(64, sizeof(INT) * 12);

    // Initialize rs strides: assume access up to rs[11], so set valid indices
    for (int i = 0; i < 12; ++i) {
        rs[i] = i; // unit stride mapping: rs[i] = i
    }

    ms = 1; // consistent with typical FFT stride
    mb = 1; // loop starts at mb
    me = N; // ensures we stay within bounds

    // Initialize cr, ci with non-zero test data to avoid degenerate math
    for (INT i = 0; i < N; ++i) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }

    // Initialize W: contains precomputed twiddle factors
    // Each block of 22 values corresponds to fixed constants per m
    for (INT i = 0; i < N; ++i) {
        R *Wp = &W[i * 22];
        for (int j = 0; j < 22; ++j) {
            Wp[j] = sin((j + 1) * 0.1) * cos((i + 1) * 0.001);
        }
    }
}