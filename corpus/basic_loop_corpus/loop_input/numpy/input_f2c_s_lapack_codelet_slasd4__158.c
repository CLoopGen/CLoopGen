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
    static_n_val = (1 << 20); // ~1M elements, adjust for ~0.01s runtime
    n = &static_n_val;
    i__1 = 1;

    size_t data_size = ((size_t)(*n)) * sizeof(real);

    static_z_ptr = (real *)aligned_alloc(32, data_size);
    static_delta_ptr = (real *)aligned_alloc(32, data_size);
    static_work_ptr = (real *)aligned_alloc(32, data_size);

    if (!static_z_ptr || !static_delta_ptr || !static_work_ptr) {
        exit(1);
    }

    z__ = static_z_ptr;
    delta = static_delta_ptr;
    work = static_work_ptr;

    for (integer i = 0; i < *n; ++i) {
        z__[i] = (real)(i + 1);
        delta[i] = (real)(i % 128 + 1);
        work[i] = (real)(i % 256 + 1);
    }

    phi = 0.0f;
    dphi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
}