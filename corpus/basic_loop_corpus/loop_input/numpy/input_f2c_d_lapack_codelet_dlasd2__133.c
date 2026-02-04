#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *z__ = NULL;
doublereal *dsigma = NULL;
doublereal *u2 = NULL;
integer *idxc = NULL;
integer *idxq = NULL;
integer *coltyp = NULL;
integer u2_dim1;
integer i__1;
integer i__;

void init_vars() {
    const integer array_size = 1 << 20; // 1 million elements, approx 8MB per array
    i__1 = array_size - 1; // ensures loop runs from 2 to array_size-1 inclusive

    d__ = (doublereal*)calloc(array_size, sizeof(doublereal));
    z__ = (doublereal*)calloc(array_size, sizeof(doublereal));
    dsigma = (doublereal*)calloc(array_size, sizeof(doublereal));
    u2 = (doublereal*)calloc(array_size * 2, sizeof(doublereal)); // at least (i__ + u2_dim1) safe
    idxc = (integer*)calloc(array_size, sizeof(integer));
    idxq = (integer*)calloc(array_size, sizeof(integer));
    coltyp = (integer*)calloc(array_size, sizeof(integer));

    u2_dim1 = array_size; // ensures u2[i__ + u2_dim1] is in bounds

    for (integer i = 0; i < array_size; ++i) {
        d__[i] = (doublereal)(i + 1) * 0.1;
        z__[i] = (doublereal)(i + 1) * 0.2;
        idxq[i] = rand() % array_size;
        coltyp[i] = rand() % 4;
    }
}