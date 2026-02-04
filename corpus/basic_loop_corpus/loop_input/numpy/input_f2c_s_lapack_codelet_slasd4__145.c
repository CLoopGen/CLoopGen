#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
real *d__;
real *delta;
real *work;
integer i__1;
integer j;
real temp1;

static integer n_storage;
static real *d__storage;
static real *delta_storage;
static real *work_storage;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // The loop runs i__1 iterations, and each iteration accesses d__[j], work[j], delta[j]
    // We assume i__1 <= *n, so set array sizes based on *n
    // Aim for about 16 million elements (~64 MB of floats) for sufficient workload
    n_storage = 8000000;  // 8 million elements
    i__1 = n_storage;

    // Allocate arrays with size n_storage + 2 to allow 1-based indexing (index 1 to n_storage)
    d__storage = (real*)calloc(n_storage + 2, sizeof(real));
    delta_storage = (real*)calloc(n_storage + 2, sizeof(real));
    work_storage = (real*)calloc(n_storage + 2, sizeof(real));

    if (!d__storage || !delta_storage || !work_storage) {
        exit(1);
    }

    // Initialize all external pointers
    n = &n_storage;
    d__ = d__storage;
    delta = delta_storage;
    work = work_storage;
    temp1 = 1.5f;

    // Initialize d__ values to avoid undefined behavior
    for (integer i = 1; i <= n_storage; ++i) {
        d__[i] = (real)(i & 0xFF);
    }
}