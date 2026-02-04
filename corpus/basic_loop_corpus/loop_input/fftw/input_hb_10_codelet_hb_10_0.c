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
E KP250000000;
E KP951056516;
E KP587785252;
E KP559016994;
INT m;

void init_vars() {
    const size_t data_size = 1 << 20;
    const INT vector_length = 10;

    cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    ci = (R*)aligned_alloc(32, data_size * sizeof(R));
    W = (R*)aligned_alloc(32, 18 * vector_length * sizeof(R));
    rs = (INT*)aligned_alloc(32, vector_length * sizeof(INT));

    for (size_t i = 0; i < data_size; ++i) {
        cr[i] = (R)(i % 1234) * 0.01;
        ci[i] = (R)(i % 5678) * 0.01;
    }
    for (int i = 0; i < 18 * vector_length; ++i) {
        W[i] = (R)(i % 18) * 0.1;
    }
    for (int i = 0; i < vector_length; ++i) {
        rs[i] = (INT)i * 2 + 1;
    }

    KP250000000 = (E)0.25;
    KP951056516 = (E)0.951056516;
    KP587785252 = (E)0.587785252;
    KP559016994 = (E)0.559016994;

    mb = 1;
    me = vector_length;
    ms = 1;
    m = mb;
}