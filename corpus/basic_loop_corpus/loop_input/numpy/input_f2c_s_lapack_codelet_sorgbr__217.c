#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *a;
integer a_dim1;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128MB of data
    a = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!a) exit(1);

    a_dim1 = 1;
    i__1 = (integer)(data_size - 1);
}