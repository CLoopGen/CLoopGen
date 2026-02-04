#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *i__;
real *d__;
real *delta;
integer i__1;
integer j;
real midpt;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(real))

void init_vars() {
    i__1 = (integer)(sqrt(DATA_SIZE) / 2);
    if (i__1 < 1) i__1 = 1;
    *i__ = i__1 - 1;

    d__ = (real *)aligned_alloc(32, (i__1 + 1) * sizeof(real));
    delta = (real *)aligned_alloc(32, (i__1 + 1) * sizeof(real));
    midpt = 123.456f;

    for (integer idx = 0; idx <= i__1; ++idx) {
        d__[idx] = (real)(idx * 2.5);
    }
}

static void __attribute__((constructor)) initialize() {
    i__ = (integer *)aligned_alloc(32, sizeof(integer));
    init_vars();
}