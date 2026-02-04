#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
INT m;

void init_vars() {
    const size_t data_size = 1 << 20; // Approximately 1M elements for ~0.01 sec runtime
    const size_t total_bytes = data_size * sizeof(R);

    cr = (R*)aligned_alloc(32, total_bytes);
    ci = (R*)aligned_alloc(32, total_bytes);
    W = (R*)aligned_alloc(32, 2 * data_size * sizeof(R)); // W accessed as W[0], W[1], etc.
    rs = (INT*)aligned_alloc(32, 8 * sizeof(INT));

    if (!cr || !ci || !W || !rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize rs values: ensure rs[1] is valid index
    rs[0] = 0;
    rs[1] = (INT)(data_size / sizeof(R)) - 1;  // Point near end to avoid out-of-bounds

    // Set stride step
    ms = 1;

    // Set loop bounds: ensure m from mb to me-1 fits with array sizes
    mb = 1;
    me = (INT)(data_size / sizeof(R)) - 1;

    // Initialize arrays to prevent NaN/undefined behavior in computation
    for (size_t i = 0; i < data_size / sizeof(R); ++i) {
        cr[i] = (R)(i + 1) * 0.1;
        ci[i] = (R)(i + 1) * 0.2;
    }
    for (size_t i = 0; i < 2 * data_size / sizeof(R); ++i) {
        W[i] = (R)(i % 100) * 0.01;
    }
}