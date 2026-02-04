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
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP222520933;
E KP900968867;
E KP623489801;
E KP781831482;
E KP974927912;
E KP433883739;
INT m;

void init_vars() {
    const size_t data_size = 1 << 20; // ~16MB total data, adjust for ~0.01s runtime
    const INT vector_length = 7;

    cr = (R*)aligned_alloc(64, sizeof(R) * data_size);
    ci = (R*)aligned_alloc(64, sizeof(R) * data_size);
    W = (R*)aligned_alloc(64, sizeof(R) * 12 * (data_size / vector_length));

    if (!cr || !ci || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    rs = (stride)aligned_alloc(64, sizeof(INT) * vector_length);
    if (!rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT i = 0; i < vector_length; ++i) {
        rs[i] = i * 2 + 1;
    }

    for (size_t i = 0; i < data_size; ++i) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }

    for (size_t i = 0; i < 12 * (data_size / vector_length); ++i) {
        W[i] = sin(i * 0.003) * cos(i * 0.007);
    }

    KP222520933 = 0.222520933;
    KP900968867 = 0.900968867;
    KP623489801 = 0.623489801;
    KP781831482 = 0.781831482;
    KP974927912 = 0.974927912;
    KP433883739 = 0.433883739;

    mb = 1;
    me = data_size / vector_length - 1;
    ms = 1;

    m = mb;
}