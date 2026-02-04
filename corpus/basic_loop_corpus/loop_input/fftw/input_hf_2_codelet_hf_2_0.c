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
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
INT m;

static size_t data_size = 1 << 20; // ~8MB per array (double)

void init_vars() {
    mb = 1;
    me = (INT)(data_size / 2); // ensures W access within bounds
    ms = 1;
    
    // Allocate arrays with padding to prevent out-of-bounds access
    cr = (R*)aligned_alloc(64, sizeof(R) * data_size);
    ci = (R*)aligned_alloc(64, sizeof(R) * data_size);
    W = (R*)aligned_alloc(64, sizeof(R) * data_size * 2); // W accessed with +2 per iteration
    rs = (INT*)aligned_alloc(64, sizeof(INT) * data_size);

    // Initialize rs values: ensure rs[1] is valid and within array bounds
    for (size_t i = 0; i < data_size; ++i) {
        rs[i] = (i + 17) % (data_size / 8); // keep index moderate
    }

    // Initialize cr, ci with non-zero values
    for (size_t i = 0; i < data_size; ++i) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }

    // Initialize W: pairs of (cos, -sin) for rotation-like factors
    for (size_t i = 0; i < data_size; ++i) {
        W[2*i]   = cos(i * 0.01);
        W[2*i+1] = -sin(i * 0.01);
    }

    // Adjust me if needed to stay in bounds
    if (me > (INT)(data_size / 2)) me = (INT)(data_size / 2);
}