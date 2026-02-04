#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer *indxq = NULL;
doublereal *z__ = NULL;
doublereal *dlamda = NULL;
doublereal *w = NULL;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 1 << 20; // 1 million elements (~8 MB per array for double)
    i__1 = (integer)data_size;

    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    z__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    dlamda = (doublereal*)calloc(data_size, sizeof(doublereal));
    w = (doublereal*)calloc(data_size, sizeof(doublereal));
    indxq = (integer*)malloc(data_size * sizeof(integer));

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (doublereal)(i + 1) * 0.5;
        z__[i] = (doublereal)(i + 1) * 1.5;
        indxq[i] = (integer)(i % data_size); // ensure valid index within bounds
    }
}