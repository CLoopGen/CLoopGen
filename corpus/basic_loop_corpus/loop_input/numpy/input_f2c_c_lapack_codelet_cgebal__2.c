#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *scale;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (~256M bytes)
    scale = (real *)aligned_alloc(32, data_size * sizeof(real));
    if (!scale) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1); // ensures scale[i__] access is in bounds for i__ from 1 to i__1
}