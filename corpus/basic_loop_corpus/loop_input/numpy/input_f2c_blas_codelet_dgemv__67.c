#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal beta_data = 2.5;
doublereal *beta = &beta_data;

doublereal *y = NULL;
integer *incy = NULL;
integer i__1 = 0;
integer i__ = 0;
integer iy = 0;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 2^20 doubles ≈ 8MB
    y = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!y) {
        exit(1);
    }
    
    for (size_t i = 0; i < data_size; ++i) {
        y[i] = (doublereal)(i + 1);
    }

    incy = (integer *)malloc(sizeof(integer));
    if (!incy) {
        exit(1);
    }
    *incy = 1;

    i__1 = (integer)data_size;
    iy = 0;
}