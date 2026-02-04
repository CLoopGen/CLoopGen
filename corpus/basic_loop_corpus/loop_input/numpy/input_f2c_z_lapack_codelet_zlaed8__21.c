#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *z__ = NULL;
doublereal *dlamda = NULL;
doublereal *w = NULL;
integer *indxq = NULL;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 67108864; // ~512 MB of total data (adjustable for ~0.01 sec runtime)

    d__ = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    z__ = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    dlamda = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    w = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    indxq = (integer*)aligned_alloc(32, data_size * sizeof(integer));

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (doublereal)(i + 1) * 0.1;
        z__[i] = (doublereal)(i + 1) * 0.2;
        indxq[i] = rand() % data_size;
    }

    i__1 = (integer)data_size - 1;
    i__ = 1;
}