#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP250000000;
E KP559016994;
E KP587785252;
E KP951056516;
INT m;

#define N 20
#define LEN 131072  // 128K elements per array -> ~1MB for cr/ci, enough for measurable time

void init_vars() {
    KP250000000 = 0.25;
    KP559016994 = sin(M_PI / 5.0);        // approx 0.587785252 * sqrt(2), but matches name
    KP587785252 = sin(2.0 * M_PI / 5.0);  // approx 0.951056516 * sqrt(2)
    KP951056516 = sin(3.0 * M_PI / 5.0);  // approx same as sin(2pi/5)

    ms = 1;
    mb = 1;
    me = LEN - 1;  // ensures m < me and W indexing within bounds

    // Allocate arrays with padding to avoid out-of-bounds access
    cr = (R*)aligned_alloc(sizeof(R), sizeof(R) * (LEN + 2*N));
    ci = (R*)aligned_alloc(sizeof(R), sizeof(R) * (LEN + 2*N));
    W = (R*)aligned_alloc(sizeof(R), sizeof(R) * (LEN * 38 + 40));  // large stride buffer
    rs = (stride)aligned_alloc(sizeof(INT), sizeof(INT) * N);

    if (!cr || !ci || !W || !rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize rs strides: assume unit strides for indices 0..19
    for (INT i = 0; i < N; i++) {
        rs[i] = i * ms;
    }

    // Initialize data arrays to prevent NaN/inf and ensure predictable behavior
    for (INT i = 0; i < LEN + 2*N; i++) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }
    for (INT i = 0; i < LEN * 38 + 40; i++) {
        W[i] = sin(i * 0.001) * 0.5 + 0.5;
    }

    // Ensure W starts at proper offset used in loop: W = W + ((mb-1)*38)
    // So we must have W base pointer such that after adding (mb-1)*38 stays in bounds
    // We already allocated extra space so this is safe.
}