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
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2
INT m;

void init_vars() {
    const INT N = 1 << 18; // ~262k elements, suitable for ~0.01s runtime
    const INT stride_size = 12; // Maximum rs index used is 11 -> need 12 strides

    // Allocate arrays with padding to prevent out-of-bounds access
    ri = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), N * 22 * sizeof(R)); // Each m uses 22 W values
    rs = (INT*)aligned_alloc(sizeof(INT), stride_size * sizeof(INT));

    // Initialize rs strides: ensure all rs[i] are valid indices within array bounds
    for (INT i = 0; i < stride_size; ++i) {
        rs[i] = i * 1024; // Use spaced strides that stay in bounds
    }

    // Set loop bounds to ensure all memory accesses are valid
    mb = 0;
    ms = 1; // pointer increment per loop
    me = N / 1024; // Adjust so max index access stays within N

    // Initialize data arrays to meaningful values
    for (INT i = 0; i < N; ++i) {
        ri[i] = sin(i);
        ii[i] = cos(i);
    }
    for (INT i = 0; i < N * 22; ++i) {
        W[i] = sin(i * 0.1) + cos(i * 0.3);
    }
}