#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *e;
integer *info;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 1 << 24; // 16 million elements ~128MB for double
    e = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!e) exit(1);

    i__1 = (integer)(data_size - 1); // Ensure index within bounds: loop from 1 to i__1 inclusive
    info = (integer*)aligned_alloc(32, sizeof(integer));
    if (!info) exit(1);
    *info = 0;

    // Initialize array e with mostly non-zero values to ensure meaningful computation
    for (size_t i = 0; i < data_size; ++i) {
        e[i] = sin(i) * 1.5; // Non-zero pattern
    }

    // Ensure e[0] is unused since loop starts at index 1
    e[0] = 0.0;
}