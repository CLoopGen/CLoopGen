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
    const size_t data_size = 2097152; // ~16MB total data, ensures ~0.01s runtime
    cr = (R*)aligned_alloc(64, data_size * sizeof(R));
    ci = (R*)aligned_alloc(64, data_size * sizeof(R));
    W = (R*)aligned_alloc(64, data_size * sizeof(R));

    for (size_t i = 0; i < data_size; i++) {
        cr[i] = (R)(i % 1234) / 100.0;
        ci[i] = (R)(i % 5678) / 100.0;
        W[i] = (R)(i % 9012) / 1000.0;
    }

    rs = (stride)aligned_alloc(64, 20 * sizeof(INT));
    for (int i = 0; i < 20; i++) {
        rs[i] = i * 4; // valid strides within bounds
    }

    mb = 1;
    me = 1 + (data_size - 38 * (mb - 1)) / 38; // ensure W access stays in bounds
    if (me > mb + 10000) me = mb + 10000;      // limit loop count for timing
    ms = 2;

    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;
}