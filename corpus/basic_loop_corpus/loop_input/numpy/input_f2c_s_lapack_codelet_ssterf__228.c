#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

real *e;
integer i__1;
real r__1;
integer i__;
integer l;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of float data
    e = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!e) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        e[i] = (real)(i % 1000) / 100.0f;
    }

    l = 0;
    i__1 = data_size - 1;
}