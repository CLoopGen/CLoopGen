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
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of doubles to ensure ~0.01s runtime
    y = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!y) exit(1);
    i__1 = (integer)(data_size - 1);
    i__ = 0;
}