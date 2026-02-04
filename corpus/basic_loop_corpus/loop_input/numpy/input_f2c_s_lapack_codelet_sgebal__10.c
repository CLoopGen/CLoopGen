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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec)
    scale = (real*)calloc(data_size, sizeof(real));
    if (!scale) {
        exit(1);
    }
    i__1 = data_size - 1; // ensures scale[i__] is in bounds for i__ from 1 to i__1
}