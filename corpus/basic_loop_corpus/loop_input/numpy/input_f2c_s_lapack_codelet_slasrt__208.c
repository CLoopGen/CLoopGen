#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float real;
typedef int integer;

real *d__;
integer i__1;
integer i__2;
integer i__;
integer j;
real dmnmx;
integer start;

static real d_internal[65536];
static const size_t data_size = 65536;

void init_vars() {
    size_t i;
    uint32_t seed = 12345;

    for (i = 0; i < data_size; ++i) {
        int32_t r = ((int32_t)rand_r(&seed)) % 20000 - 10000;
        d_internal[i] = (real)r;
    }

    d__ = d_internal;
    start = 1;
    i__1 = (integer)(data_size - 1);

    i__ = 0;
    j = 0;
    dmnmx = 0.0f;
    i__2 = 0;
}