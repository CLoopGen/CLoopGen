#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *y;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 1 << 24; // ~16.7 million elements, roughly 128MB for doubles
    y = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!y) {
        exit(1);
    }
    i__1 = data_size - 1; // ensures y[i__] access is within bounds for i__ from 1 to i__1
    i__ = 0;
}