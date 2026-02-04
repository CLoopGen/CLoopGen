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

// Data size: aim for ~64k elements to ensure loop runs ~0.01s on modern CPU
static const INT N = 65536;

// Declare arrays with sufficient size
R *ri = NULL;
R *ii = NULL;
R *W = NULL;
stride rs = NULL;

INT mb = 0;
INT me = N;
INT ms = 1;
INT m;

E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;

void init_vars() {
    // Allocate memory for arrays
    ri = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), 30 * N * sizeof(R)); // Each m uses 30 elements
    rs = (INT*)aligned_alloc(sizeof(INT), 16 * sizeof(INT)); // rs[15] max used

    // Initialize rs strides: assume unit stride for all indices
    for (INT i = 0; i < 16; ++i) {
        rs[i] = i;
    }

    // Initialize input data to prevent NaN/Inf and ensure defined behavior
    for (INT i = 0; i < N; ++i) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
    }

    // Initialize twiddle factors W: each block of 30 values per m
    for (INT idx = 0; idx < 30 * N; ++idx) {
        W[idx] = sin(idx * 0.1); // Arbitrary smooth initialization
    }

    // Set bounds so that loop index m goes from mb to me-1 safely
    mb = 0;
    me = N;

    // Ensure ms is valid (used in pointer arithmetic)
    ms = 1;

    // Sanity check allocations
    if (!ri || !ii || !W || !rs) {
        exit(1);
    }
}