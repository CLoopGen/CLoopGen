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
R *ro;
R *io;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2
E KP500000000 = 0.5;
INT i;

void init_vars() {
    const size_t N = 12; // Based on index usage: is[11] is max
    const size_t total_size = (1 << 20) / sizeof(R); // ~1MB of data, adjust for double

    // Ensure v is such that we process about total_size elements
    v = total_size / N;
    if (v == 0) v = 1;

    // Allocate arrays with padding to prevent out-of-bounds access
    size_t alloc_size = v * N + 16;
    ri = (R*)aligned_alloc(sizeof(R), alloc_size * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), alloc_size * sizeof(R));
    ro = (R*)aligned_alloc(sizeof(R), alloc_size * sizeof(R));
    io = (R*)aligned_alloc(sizeof(R), alloc_size * sizeof(R));

    is = (stride)aligned_alloc(sizeof(INT), 16 * sizeof(INT));
    os = (stride)aligned_alloc(sizeof(INT), 16 * sizeof(INT));

    // Set strides: assume unit stride for input/output spacing
    for (int j = 0; j < 16; ++j) {
        is[j] = j;
        os[j] = j;
    }

    ivs = N; // Input vector stride
    ovs = N; // Output vector stride

    // Initialize data arrays with non-zero values to avoid trivial optimizations
    for (size_t j = 0; j < alloc_size; ++j) {
        ri[j] = sin(j * 0.01);
        ii[j] = cos(j * 0.01);
        ro[j] = 0.0;
        io[j] = 0.0;
    }
}