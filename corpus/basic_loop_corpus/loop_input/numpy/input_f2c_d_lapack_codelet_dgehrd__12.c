#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *tau;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 1 << 24; // ~16.7 million elements, ~134 MB for doubles
    tau = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!tau) {
        exit(1);
    }
    i__1 = (integer)(data_size - 1);
    i__ = 0;
}