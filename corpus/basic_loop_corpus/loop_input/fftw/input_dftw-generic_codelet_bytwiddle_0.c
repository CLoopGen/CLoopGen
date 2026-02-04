#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *rio;
R *iio;
INT iv;
INT ir;
INT im;
INT r;
INT rs;
INT m;
INT mb;
INT me;
INT ms;
INT v;
INT vs;
INT mb;
INT me;
INT ms;
INT v;
INT vs;
R *W;

void init_vars() {
    // Set parameters to ensure reasonable data size and avoid out-of-bounds access
    m = 128;
    r = 8;
    v = 1000;
    vs = 2 * m;
    rs = 2;
    ms = 2;
    mb = 0;
    me = m;
    
    // Allocate input/output arrays: each of size v * (2*m) real numbers
    size_t total_size = v * vs;
    rio = (R*)aligned_alloc(32, total_size * sizeof(R));
    iio = (R*)aligned_alloc(32, total_size * sizeof(R));
    
    // Initialize data to non-zero for meaningful computation
    for (size_t i = 0; i < total_size; ++i) {
        rio[i] = sin(i * 0.01);
        iio[i] = cos(i * 0.01);
    }
    
    // W stores complex coefficients: [re, im] pairs for each (im, ir)
    // Index used: 2 * im + (2 * (m - 1)) * ir - 2  --> must be in bounds
    // Max index: 2*me + 2*(m-1)*r - 2 ≈ 2*m + 2*(m-1)*r
    size_t w_size = 2 * (m - 1) * r + 2 * me;
    W = (R*)aligned_alloc(32, w_size * sizeof(R));
    
    for (size_t i = 0; i < w_size; ++i) {
        W[i] = sin(i * 0.1) * 0.5 + 1.0;
    }
}