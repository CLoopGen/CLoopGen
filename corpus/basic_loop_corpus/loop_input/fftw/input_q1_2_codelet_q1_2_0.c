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
R *rio = NULL;
R *iio = NULL;
R *W = NULL;
stride rs = NULL;
stride vs = NULL;
INT mb = 0;
INT me = 0;
INT ms = 0;
INT m = 0;

void init_vars() {
    const size_t N = (1 << 20); // ~16MB total data: adjust as needed for ~0.01s runtime

    rio = aligned_alloc(32, N * sizeof(R));
    iio = aligned_alloc(32, N * sizeof(R));
    W = aligned_alloc(32, 2 * N * sizeof(R));

    rs = aligned_alloc(32, 2 * sizeof(INT));
    vs = aligned_alloc(32, 2 * sizeof(INT));

    // Initialize strides
    rs[0] = 0; rs[1] = 1;
    vs[0] = 0; vs[1] = N / 4;

    ms = 1;
    mb = 0;
    me = N / 4;  // Ensure m < me and all array accesses are within [0, N-1]

    // Initialize data arrays with non-zero values for meaningful computation
    for (size_t i = 0; i < N; ++i) {
        rio[i] = sin(i * 0.01);
        iio[i] = cos(i * 0.01);
    }

    for (size_t i = 0; i < 2 * N; ++i) {
        W[i] = (i % 2 == 0) ? 1.0 : 0.1 * (i / 2);
    }
}