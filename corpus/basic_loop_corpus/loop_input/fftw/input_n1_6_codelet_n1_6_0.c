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
    const size_t data_size = 1 << 20; // ~16 MB of complex data (each array is 8MB)
    const INT vec_length = 6; // Based on is[5] and os[5] being accessed

    // Allocate arrays with sufficient size
    ri = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    ro = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    io = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    is = (INT*)aligned_alloc(sizeof(INT), vec_length * sizeof(INT));
    os = (INT*)aligned_alloc(sizeof(INT), vec_length * sizeof(INT));

    // Initialize stride arrays: assume decimation-in-time FFT ordering
    for (INT idx = 0; idx < vec_length; ++idx) {
        is[idx] = idx * (data_size / vec_length);
        os[idx] = idx * (data_size / vec_length);
    }

    // Set vectorization and stride parameters
    v = data_size / vec_length; // Number of iterations
    ivs = 1; // Input stride increment per iteration
    ovs = 1; // Output stride increment per iteration

    // Initialize input data to non-zero values to avoid degenerate cases
    for (size_t j = 0; j < data_size; ++j) {
        ri[j] = sin(j * 0.01);
        ii[j] = cos(j * 0.01);
        ro[j] = 0.0;
        io[j] = 0.0;
    }
}