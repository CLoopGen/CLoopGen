#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *y;
integer *incy;
integer i__1;
integer i__;
integer iy;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of doublereal data
    y = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!y) exit(1);

    incy = (integer *)malloc(sizeof(integer));
    if (!incy) exit(1);

    *incy = 1;
    i__1 = data_size - 1;
    i__ = 1;
    iy = 0;

    for (size_t i = 0; i < data_size; ++i) {
        y[i] = (doublereal)(i + 1);
    }
}