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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for ~0.01 sec runtime estimate
    scale = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!scale) {
        exit(1);
    }

    k = 0;
    i__1 = data_size - 1;
    i__ = k;
}