#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef float real;
typedef int integer;

real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;
integer k3;
integer k4;
real mul;

void init_vars() {
    const size_t target_size_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const size_t min_dim = 8000;

    a_dim1 = (target_size_bytes / sizeof(real)) / min_dim;
    if (a_dim1 < min_dim) a_dim1 = min_dim;

    size_t total_elements = a_dim1 * a_dim1;
    a = (real*)aligned_alloc(32, total_elements * sizeof(real));
    if (!a) abort();

    memset(a, 0, total_elements * sizeof(real));

    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx] = 1.0f + (idx % 1000) * 0.001f;
    }

    k3 = a_dim1 - 100;
    k4 = a_dim1 + 50;
    i__1 = a_dim1 - 150;

    mul = 1.5f;

    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
}