#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

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
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total input data (adjustable)
    const INT vector_count = data_size / (sizeof(R) * 2); // two arrays: ri, ii

    // Ensure at least one iteration
    v = (vector_count > 0) ? vector_count : 1;

    ivs = 1;
    ovs = 1;

    // Allocate memory for ri, ii, ro, io
    ri = (R*)aligned_alloc(64, sizeof(R) * v * ivs);
    ii = (R*)aligned_alloc(64, sizeof(R) * v * ivs);
    ro = (R*)aligned_alloc(64, sizeof(R) * v * ovs);
    io = (R*)aligned_alloc(64, sizeof(R) * v * ovs);

    // Allocate and initialize stride arrays
    is = (stride)aligned_alloc(64, sizeof(INT) * 2);
    os = (stride)aligned_alloc(64, sizeof(INT) * 2);

    is[0] = 0;
    is[1] = 1;
    os[0] = 0;
    os[1] = 1;

    // Initialize data to prevent undefined behavior
    for (INT j = 0; j < v * ivs; j++) {
        ri[j] = (R)(j + 1);
        ii[j] = (R)(-(j + 1));
    }
    for (INT j = 0; j < v * ovs; j++) {
        ro[j] = 0.0;
        io[j] = 0.0;
    }

    // Ensure loop bounds are safe: access indices 0 and is[1]=1 => need at least 2 elements per vector
    if (v * ivs < 2 || v * ovs < 2) {
        fprintf(stderr, "Error: insufficient vector size\n");
        exit(1);
    }

    i = v; // initial loop counter
}