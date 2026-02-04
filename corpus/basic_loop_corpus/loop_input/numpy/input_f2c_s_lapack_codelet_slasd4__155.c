#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *z__;
real *delta;
real *work;
integer i__1;
integer j;
real phi;
real dphi;
real temp;
real erretm;

static integer static_n_val;
static real *static_z_ptr;
static real *static_delta_ptr;
static real *static_work_ptr;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Assuming moderate CPU speed and cache behavior, use ~16M elements for sufficient workload
    const size_t array_size = 1 << 24; // 16,777,216 elements

    static_n_val = (integer)array_size;
    n = &static_n_val;

    i__1 = 1; // loop runs from j = *n down to i__1 inclusive

    // Allocate arrays
    static_z_ptr = (real*)aligned_alloc(32, array_size * sizeof(real));
    static_delta_ptr = (real*)aligned_alloc(32, array_size * sizeof(real));
    static_work_ptr = (real*)aligned_alloc(32, array_size * sizeof(real));

    z__ = static_z_ptr;
    delta = static_delta_ptr;
    work = static_work_ptr;

    // Initialize arrays with non-zero values to avoid division by zero
    for (size_t i = 0; i < array_size; ++i) {
        z__[i] = (real)(i + 1) * 0.1f;
        delta[i] = (real)(i + 1) * 0.01f + 1.0f;
        work[i] = (real)(i + 1) * 0.05f + 2.0f;
    }

    // Initialize scalars
    phi = 0.0f;
    dphi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
}