#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP250000000 = 0.250000000;
E KP559016994 = 0.559016994;
E KP500000000 = 0.500000000;
E KP866025403 = 0.866025403;
INT i;

void init_vars() {
    const size_t data_size = (1 << 20); // ~1MB of complex data (each double is 8 bytes)
    const INT vec_len = 15; // Maximum index used: is[14], os[14] -> need at least 15 elements

    // Allocate arrays with padding to prevent out-of-bounds access
    ri = (R*)aligned_alloc(64, sizeof(R) * (data_size + vec_len));
    ii = (R*)aligned_alloc(64, sizeof(R) * (data_size + vec_len));
    ro = (R*)aligned_alloc(64, sizeof(R) * (data_size + vec_len));
    io = (R*)aligned_alloc(64, sizeof(R) * (data_size + vec_len));

    is = (stride)aligned_alloc(64, sizeof(INT) * vec_len);
    os = (stride)aligned_alloc(64, sizeof(INT) * vec_len);

    // Initialize stride arrays: assume unit strides for simplicity
    for (INT idx = 0; idx < vec_len; ++idx) {
        is[idx] = idx;
        os[idx] = idx;
    }

    // Set vector count and strides
    v = data_size / vec_len; // Number of iterations
    ivs = vec_len; // Input vector stride step
    ovs = vec_len; // Output vector stride step

    // Initialize input data to non-zero values to ensure meaningful computation
    for (size_t idx = 0; idx < data_size + vec_len; ++idx) {
        ri[idx] = (R)(idx % 100) * 0.01;
        ii[idx] = (R)((idx + 10) % 100) * 0.01;
        ro[idx] = 0.0;
        io[idx] = 0.0;
    }
}