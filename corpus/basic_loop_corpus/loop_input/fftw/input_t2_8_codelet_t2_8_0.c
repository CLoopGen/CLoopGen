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
R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP707106781;
INT m;

static size_t data_size;
static INT vector_length;

void init_vars() {
    KP707106781 = 0.70710678118654752440; // Approximation of 1/sqrt(2)
    vector_length = 8; // The loop uses rs indices up to 7, so we need at least 8 elements
    mb = 0;
    ms = vector_length; // Stride step for ri and ii arrays

    // Determine problem size to achieve ~0.01s runtime estimate
    // Each iteration processes one "vector" of 8 complex numbers
    // Aim for roughly 1 million iterations as a baseline for 0.01s on modern CPU
    me = 131072; // 131072 iterations

    data_size = (size_t)me * (size_t)ms;

    // Allocate aligned memory to prevent issues and simulate FFTW-like layout
    ri = aligned_alloc(sizeof(R), data_size * sizeof(R));
    ii = aligned_alloc(sizeof(R), data_size * sizeof(R));
    W = aligned_alloc(sizeof(R), (size_t)(me - mb) * 6 * sizeof(R));
    rs = aligned_alloc(sizeof(INT), vector_length * sizeof(INT));

    // Initialize rs: maps logical index to actual offset in ri/ii
    for (INT i = 0; i < vector_length; ++i) {
        rs[i] = i;
    }

    // Initialize input arrays with non-zero predictable values to avoid division by zero or no-op computations
    for (size_t i = 0; i < data_size; ++i) {
        ri[i] = sin((double)(i)) * 0.01;
        ii[i] = cos((double)(i)) * 0.01;
    }

    // Initialize W array: contains precomputed twiddle factors
    // W[6*m + 0..5] = [cos(u), sin(u), cos(v), sin(v), cos(w), sin(w)] for various angles
    for (INT idx = 0; idx < (me - mb); ++idx) {
        double angle1 = 2.0 * M_PI * idx / 16.0;
        double angle2 = 2.0 * M_PI * idx / 8.0;
        double angle3 = 2.0 * M_PI * idx / 32.0;

        W[idx*6 + 0] = cos(angle1);
        W[idx*6 + 1] = sin(angle1);
        W[idx*6 + 2] = cos(angle2);
        W[idx*6 + 3] = sin(angle2);
        W[idx*6 + 4] = cos(angle3);
        W[idx*6 + 5] = sin(angle3);
    }
}