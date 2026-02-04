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
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
INT m;

void init_vars() {
    const size_t data_size = 1 << 20; // ~16MB of complex data (each R is 8 bytes)
    const INT vector_length = 10; // rs indices go up to 9, so we need at least 10

    cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    ci = (R*)aligned_alloc(32, data_size * sizeof(R));
    W = (R*)aligned_alloc(32, data_size * sizeof(R));

    rs = (INT*)aligned_alloc(32, vector_length * sizeof(INT));
    for (INT i = 0; i < vector_length; ++i) {
        rs[i] = i; // simple stride: rs[i] = i
    }

    // Initialize constants
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;

    // Set loop bounds
    mb = 1;
    me = (data_size / 18) - 1; // Ensure W + ((mb-1)*18) and subsequent +18 steps stay in bounds
    ms = 1;

    // Initialize arrays to avoid NaN/undefined behavior
    for (size_t i = 0; i < data_size; ++i) {
        cr[i] = (R)(i % 100) * 0.01;
        ci[i] = (R)((i + 10) % 100) * 0.01;
        W[i] = (R)((i + 45) % 100) * 0.01;
    }
}