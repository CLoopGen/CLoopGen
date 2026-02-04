#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *sr;
real *si;
integer i__1;
integer i__;
real swap;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB total data
    const size_t n = data_size / (2 * sizeof(real)); // Each array has half size in elements

    sr = (real*)aligned_alloc(32, (n + 3) * sizeof(real));
    si = (real*)aligned_alloc(32, (n + 3) * sizeof(real));

    for (size_t idx = 0; idx < n + 3; ++idx) {
        sr[idx] = sinf(idx);
        si[idx] = cosf(idx);
    }

    i__1 = (integer)(n - 3); // Ensure i__+2 is within bounds when i__ <= i__1 and step by 2
    if (i__1 % 2 != 1) {
        i__1 = i__1 - 1;
    }
    i__ = 1;
    swap = 0.0f;
}