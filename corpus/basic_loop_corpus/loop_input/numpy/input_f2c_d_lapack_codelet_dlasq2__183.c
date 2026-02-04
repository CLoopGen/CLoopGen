#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
integer i__1;
integer i0;
integer i4;
integer ipn4;
doublereal temp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data
    z__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!z__) {
        exit(1);
    }

    // Initialize the array with some values to avoid all zeros
    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = (doublereal)(i & 0xFF);
    }

    i0 = 1;
    i__1 = (integer)(data_size - 8); // Ensure upper bound keeps access in range
    ipn4 = (integer)(data_size + 4); // So that ipn4 - i4 - 5 >= 0 when i4 is max
}