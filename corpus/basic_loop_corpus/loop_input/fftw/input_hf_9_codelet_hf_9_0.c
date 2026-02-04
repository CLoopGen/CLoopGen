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
E KP642787609 = 0.642787609;
E KP766044443 = 0.766044443;
E KP939692620 = 0.939692620;
E KP342020143 = 0.342020143;
E KP984807753 = 0.984807753;
E KP173648177 = 0.173648177;
E KP500000000 = 0.500000000;
E KP866025403 = 0.866025403;
INT m;

static size_t data_size;
static INT vector_length;

void init_vars() {
    vector_length = 9; // maximum index used: rs[8] -> needs 9 elements
    mb = 1;
    ms = 1;
    me = 100000; // adjust to control loop iterations

    // Estimate total memory usage to hit ~64-128MB range
    data_size = (size_t)me * 20; // rough estimate per iteration
    if (data_size < (1 << 20)) data_size = (1 << 20); // at least 1MB
    if (data_size > (256 << 20)) data_size = (256 << 20); // cap at 256MB

    // Allocate cr and ci with padding for rs offsets
    cr = (R*)aligned_alloc(64, sizeof(R) * (data_size + vector_length * 8));
    ci = (R*)aligned_alloc(64, sizeof(R) * (data_size + vector_length * 8));
    W = (R*)aligned_alloc(64, sizeof(R) * (me * 16 + 16));

    // Allocate and initialize stride array
    rs = (stride)malloc(sizeof(INT) * vector_length);
    for (INT i = 0; i < vector_length; i++) {
        rs[i] = i * 10 + 1; // ensure spaced access within bounds
    }

    // Initialize cr, ci with non-zero values to avoid degenerate math
    for (size_t i = 0; i < data_size + vector_length * 8; i++) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }

    // Initialize W: each block of 16 doubles starting from W + (mb-1)*16
    for (INT blk = 0; blk < me + 2; blk++) {
        for (INT i = 0; i < 16; i++) {
            W[(blk * 16) + i] = sin((blk + 1) * (i + 1) * 0.1);
        }
    }

    // Ensure initial W pointer offset is correct as in loop
    W += ((mb - 1) * 16);
}