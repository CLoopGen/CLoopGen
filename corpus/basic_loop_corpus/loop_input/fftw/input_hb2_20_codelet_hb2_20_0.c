#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

void init_vars() {
    const INT N = 20; // Based on rs[19] being accessed, we need at least 20 elements in some arrays
    const INT data_size = 1 << 20; // ~8MB per array (double), total ~24MB — enough for measurable runtime
    const INT num_iters = data_size / N;

    // Allocate memory
    cr = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    ci = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    W = (R*)aligned_alloc(8 * num_iters * sizeof(R), 8 * num_iters * sizeof(R)); // W is advanced by 8 each loop
    rs = (stride)malloc(N * sizeof(INT));

    // Initialize constants
    KP250000000 = 0.25;
    KP559016994 = 0.559016994;
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;

    // Initialize rs strides: assume unit stride with possible negative for ci
    for (INT i = 0; i < N; ++i) {
        rs[i] = i; // rs[0..19] used in indexing
    }

    // Set loop bounds
    mb = 0;
    me = num_iters;
    ms = 1; // arbitrary, but must be consistent

    // Initialize input arrays with non-zero values to avoid degenerate math
    for (INT i = 0; i < data_size; ++i) {
        cr[i] = (R)(i % 100) * 0.01;
        ci[i] = (R)((i + 10) % 100) * 0.01;
    }

    // Initialize W: needs at least 8*(me-mb) elements, each block of 8 used per iteration
    for (INT i = 0; i < 8 * num_iters; ++i) {
        W[i] = (R)((i * 7) % 100) * 0.01;
    }
}