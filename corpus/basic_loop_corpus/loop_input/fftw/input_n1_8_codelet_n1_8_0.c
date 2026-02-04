#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP707106781;
INT i;

static size_t data_size;

void init_vars() {
    const INT vector_size = 16;
    const INT n = 1048576; // ~256MB of total data (adjustable)
    data_size = n * vector_size * sizeof(R);

    ri = aligned_alloc(32, data_size);
    ii = aligned_alloc(32, data_size);
    ro = aligned_alloc(32, data_size);
    io = aligned_alloc(32, data_size);
    is = malloc(vector_size * sizeof(INT));
    os = malloc(vector_size * sizeof(INT));

    v = n;
    ivs = vector_size;
    ovs = vector_size;
    KP707106781 = 0.707106781; // Approximation of 1/sqrt(2)

    for (INT j = 0; j < vector_size; ++j) {
        is[j] = j;
        os[j] = j;
    }

    for (size_t k = 0; k < n * vector_size; ++k) {
        ri[k] = sin(k * 0.01);
        ii[k] = cos(k * 0.01);
        ro[k] = 0.0;
        io[k] = 0.0;
    }
}