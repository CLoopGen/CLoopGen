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
integer *indx = NULL;
integer i__1 = 0;
integer i__ = 0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024 / sizeof(doublereal); // ~512MB total for arrays, adjust to hit ~0.01s runtime
    i__1 = (integer)data_size;

    d__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    z__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    dlamda = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));
    w = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));
    indx = (integer*)malloc((i__1 + 1) * sizeof(integer));

    for (integer i = 1; i <= i__1; ++i) {
        dlamda[i] = (doublereal)(i * 1.5);
        w[i] = (doublereal)(i * 2.7);
        indx[i] = rand() % i__1 + 1;
    }
}