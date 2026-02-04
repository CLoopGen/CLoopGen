#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *h__ = NULL;
doublereal *wr = NULL;
doublereal *wi = NULL;
integer h_dim1;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of data (assuming double precision)
    h_dim1 = (integer)1024;
    i__1 = (integer)1024;

    h__ = (doublereal *)calloc((size_t)(i__1 + 1) * (size_t)(h_dim1 + 1), sizeof(doublereal));
    wr = (doublereal *)calloc((size_t)(i__1 + 1), sizeof(doublereal));
    wi = (doublereal *)calloc((size_t)(i__1 + 1), sizeof(doublereal));

    if (!h__ || !wr || !wi) {
        exit(1);
    }
}