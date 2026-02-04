#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
integer a_dim1;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128MB of data
    a = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!a) {
        exit(1);
    }

    a_dim1 = 1;
    i__1 = data_size - 1;
    i__ = 0;
}