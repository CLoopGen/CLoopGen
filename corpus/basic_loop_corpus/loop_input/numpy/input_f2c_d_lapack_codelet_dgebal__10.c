#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *scale;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data to target ~0.01 sec runtime
    scale = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!scale) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1);
    i__ = 0;
}