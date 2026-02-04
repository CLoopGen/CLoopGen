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
INT m;

void init_vars() {
    // Initialize constants
    KP587785252 = 0.587785252;  // approx sin(2*pi/10)
    KP951056516 = 0.951056516;  // approx sin(4*pi/10)
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;  // approx sqrt(5)/4

    // Define problem size parameters
    const INT N = 131072;  // Adjust to get ~0.01s runtime (tune as needed)
    mb = 0;
    me = N;
    ms = 1;

    // Allocate arrays with sufficient size to avoid out-of-bounds access
    ri = (R*)aligned_alloc(64, sizeof(R) * N * 10);
    ii = (R*)aligned_alloc(64, sizeof(R) * N * 10);
    W = (R*)aligned_alloc(64, sizeof(R) * (me - mb) * 18 + 18);

    // Allocate and initialize stride array (rs has indices up to 9)
    rs = (stride)malloc(sizeof(INT) * 10);
    for (INT i = 0; i < 10; ++i) {
        rs[i] = i;  // assume unit strides for simplicity
    }

    // Initialize input data to prevent NaN/undefined behavior
    for (INT i = 0; i < N * 10; ++i) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
    }

    // Initialize twiddle factors W: each block of 18 elements per iteration
    for (INT i = 0; i < (me - mb) * 18 + 18; ++i) {
        W[i] = sin(i * 0.1) * cos(i * 0.03);
    }
}