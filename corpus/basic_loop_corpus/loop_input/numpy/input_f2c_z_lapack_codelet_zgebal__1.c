#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *scale;
integer i__1;
integer i__;
integer k;

void init_vars() {
    const size_t data_size = 134217728; // 128MB of doubles (each double is 8 bytes)
    scale = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!scale) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        scale[idx] = 0.0;
    }

    k = 0;
    i__1 = (integer)(data_size - 1);
}