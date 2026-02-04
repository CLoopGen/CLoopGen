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
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2
E KP500000000 = 0.5;
INT m;

void init_vars() {
    const size_t data_size = 1 << 20; // ~16MB total data (adjustable)
    const INT vector_length = 3;

    ri = (R*)aligned_alloc(64, data_size * sizeof(R));
    ii = (R*)aligned_alloc(64, data_size * sizeof(R));
    W = (R*)aligned_alloc(64, data_size * sizeof(R));

    if (!ri || !ii || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    rs = (stride)aligned_alloc(64, vector_length * sizeof(INT));
    if (!rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        ri[i] = sin(i * 0.01);
        ii[i] = cos(i * 0.01);
        W[i] = sin(i * 0.02) * cos(i * 0.03);
    }

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;

    mb = 0;
    me = (data_size / 4); // Ensure W access with +4 stride stays in bounds
    if (me > (data_size - 4)) me = data_size - 4;
    ms = 1;
}