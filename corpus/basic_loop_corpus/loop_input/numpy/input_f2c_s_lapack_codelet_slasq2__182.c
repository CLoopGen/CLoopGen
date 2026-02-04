#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *z__;
integer i__1;
integer k;

void init_vars() {
    i__1 = 131072; // Ensures z__ has at least 262143 elements (since index (k<<1)-1 can reach (i__1<<1)-1)
    size_t array_size = ((size_t)i__1 << 1); // Allocate enough to cover all indexed positions safely

    z__ = (real*)calloc(array_size, sizeof(real));
    if (!z__) {
        exit(1);
    }

    // Initialize the array with some values to avoid undefined behavior when reading
    for (size_t i = 0; i < array_size; ++i) {
        z__[i] = (real)(i + 1);
    }
}