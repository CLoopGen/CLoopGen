#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *y;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 million floats = ~256 MB
    y = (real*)calloc(data_size, sizeof(real));
    if (!y) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1);
}