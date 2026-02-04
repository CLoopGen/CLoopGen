#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Declare arrays with sufficient size to avoid out-of-bounds access
// Based on the loop accessing rs[19], ri[ii] with offsets up to 19*rs stride
// and W accessed with +8 offset per iteration

static R *ri_data = NULL;
static R *ii_data = NULL;
static R *W_data = NULL;
static INT *rs_data = NULL;

R *ri;
R *ii;
R *W;
stride rs;
INT mb = 0;
INT me = 2000; // Adjust for ~0.01s runtime (empirically tuned)
INT ms = 1;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP250000000 = 0.250000000;
E KP559016994 = 0.559016994;
INT m;

void init_vars() {
    const INT N = 20; // maximum index used in rs[..]
    const INT W_size = (me - mb) * 8 + 10; // enough for W + (mb*8) + 8*(me-mb)
    const INT data_size = 32 * 1024; // ~256KB per array

    // Allocate memory
    ri_data = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    ii_data = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    W_data = (R*)aligned_alloc(sizeof(R), W_size * sizeof(R));
    rs_data = (INT*)malloc(N * sizeof(INT));

    // Initialize rs strides: assume unit stride for consecutive elements
    for (INT i = 0; i < N; i++) {
        rs_data[i] = i;
    }

    // Initialize data arrays with non-zero values to avoid trivial optimization
    for (INT i = 0; i < data_size; i++) {
        ri_data[i] = sin(i * 0.01);
        ii_data[i] = cos(i * 0.01);
    }

    // Initialize W array with constants derived from trigonometric values
    for (INT i = 0; i < W_size; i++) {
        W_data[i] = sin((i % 16) * 0.1) * 1.5;
    }

    // Set global pointers
    ri = ri_data;
    ii = ii_data;
    W = W_data;
    rs = rs_data;

    // Ensure mb and me are within safe bounds
    mb = 0;
    me = (W_size - 8) / 8; // ensures W + (mb*8) + 8*(me-mb) stays in bounds
    if (me > 2000) me = 2000;
    ms = 1;
}