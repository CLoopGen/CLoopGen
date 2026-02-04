#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer *indxq = NULL;
doublereal *dlamda = NULL;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01s runtime

    i__1 = (integer)data_size;

    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    indxq = (integer*)malloc(data_size * sizeof(integer));
    dlamda = (doublereal*)malloc(data_size * sizeof(doublereal));

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (doublereal)(i + 1) * 0.5;
        indxq[i] = (integer)i;
    }
}