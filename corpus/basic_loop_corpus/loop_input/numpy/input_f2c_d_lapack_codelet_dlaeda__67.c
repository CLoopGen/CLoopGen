#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
integer i__1;
integer k;
integer mid;
integer bsiz2;

void init_vars() {
    mid = 0;
    bsiz2 = 1048576;  // 1MB / sizeof(double) = 131072 elements, but we adjust for ~0.01s runtime
    i__1 = bsiz2 * 2 - 1;  // ensures loop runs over a large array

    size_t array_size = (i__1 + 1);
    z__ = (doublereal*)calloc(array_size, sizeof(doublereal));
    if (!z__) {
        exit(1);
    }
}