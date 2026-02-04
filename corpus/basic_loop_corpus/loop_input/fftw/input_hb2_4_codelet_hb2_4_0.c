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
INT m;

static const size_t DATA_SIZE = 1 << 20; // ~16MB of total data (adjustable)

void init_vars() {
    // Allocate data arrays
    cr = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    ci = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    W = (R*)aligned_alloc(32, (DATA_SIZE / 4) * sizeof(R)); // W accessed with step 4

    // Allocate and initialize stride array
    rs = (INT*)aligned_alloc(32, 8 * sizeof(INT)); // rs[1], rs[2], rs[3] used

    // Initialize rs values to valid small strides
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    // Set loop parameters
    mb = 1;
    me = (DATA_SIZE / 4) - 10;  // Ensure W + ((me-1)*4)+3 is in bounds
    ms = 1;

    // Initialize arrays to prevent NaN/undefined behavior in arithmetic
    for (size_t i = 0; i < DATA_SIZE; ++i) {
        if (i < DATA_SIZE / 4) {
            W[i] = (R)(1.0 + (i % 7)); // non-zero values for W
        }
        if (i < me * 4) {
            cr[i] = (R)(i + 1);
            ci[i] = (R)(-(ptrdiff_t)i);
        }
    }
}