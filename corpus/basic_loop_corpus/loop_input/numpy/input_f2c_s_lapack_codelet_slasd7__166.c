#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float real;
typedef int integer;

real *d__;
real *z__;
real *zw;
real *vf;
real *vfw;
real *vl;
real *vlw;
real *dsigma;
integer *idx;
integer i__1;
integer i__;
integer idxi;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256MB of total data (adjustable)
    
    // Allocate arrays
    d__ = (real*)calloc(data_size, sizeof(real));
    z__ = (real*)calloc(data_size, sizeof(real));
    zw = (real*)calloc(data_size, sizeof(real));
    vf = (real*)calloc(data_size, sizeof(real));
    vfw = (real*)calloc(data_size, sizeof(real));
    vl = (real*)calloc(data_size, sizeof(real));
    vlw = (real*)calloc(data_size, sizeof(real));
    dsigma = (real*)calloc(data_size, sizeof(real));
    idx = (integer*)malloc(data_size * sizeof(integer));

    // Initialize idx array to valid indices (0 to data_size-1), ensuring idx[i] + 1 is in bounds
    for (size_t j = 0; j < data_size; ++j) {
        idx[j] = rand() % (data_size - 1); // guarantees idx[j] + 1 < data_size
    }

    // Initialize dsigma, zw, vfw, vlw with dummy data
    for (size_t j = 0; j < data_size; ++j) {
        dsigma[j] = 1.0f + (rand() % 100) * 0.01f;
        zw[j] = 2.0f + (rand() % 100) * 0.02f;
        vfw[j] = 3.0f + (rand() % 100) * 0.03f;
        vlw[j] = 4.0f + (rand() % 100) * 0.04f;
    }

    // Set loop bounds: aim for enough iterations to take ~0.01s
    // On modern CPUs, simple loops like this run ~1e9 iterations/sec,
    // so 10M iterations ≈ 0.01s. But we use full data_size if smaller.
    i__1 = (integer)((data_size > 10000000) ? 10000000 : data_size - 1);
    i__ = 2;
}