#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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

static integer _n_val;
static real *_z__arr;
static real *_delta_arr;
static real *_work_arr;

void init_vars() {
    // Allocate approximately 64MB of data to target ~0.01s runtime
    // Each array has N elements of float (4 bytes), so total = 3 * N * 4 = 12N bytes
    // For 64MB: N ≈ 64 * 1024 * 1024 / 12 ≈ 5.7M
    const size_t N = 5700000;

    // Allocate arrays
    _z__arr = (real*)calloc(N + 1, sizeof(real));
    _delta_arr = (real*)calloc(N + 1, sizeof(real));
    _work_arr = (real*)calloc(N + 1, sizeof(real));

    if (!_z__arr || !_delta_arr || !_work_arr) {
        exit(1);
    }

    // Initialize arrays with non-zero values to avoid division by zero
    for (size_t i = 1; i <= N; ++i) {
        _z__arr[i] = (real)(sin((double)i) * 100.0f);
        _delta_arr[i] = (real)(fabs(cos((double)i)) + 1.0f); // Ensure positive and non-zero
        _work_arr[i] = (real)(fabs(sin((double)i)) + 1.0f);  // Ensure positive and non-zero
    }

    // Set global pointers
    z__ = _z__arr;
    delta = _delta_arr;
    work = _work_arr;

    // Set loop bounds: j from *n down to i__1
    _n_val = (integer)N;
    n = &_n_val;
    i__1 = 1;  // ensures j goes from N down to 1, valid index range [1..N]

    // Initialize phi to zero
    phi = 0.0f;
}