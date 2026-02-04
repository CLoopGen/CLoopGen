#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
doublereal *beta;
doublereal *vt;
integer vt_dim1;
integer i__1;
integer i__;
integer nlp2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of data for vt, adjust as needed

    vt_dim1 = (integer)(data_size / sizeof(doublereal) / 2); 
    nlp2 = 1;
    i__1 = (integer)(data_size / sizeof(doublereal)) - 1;

    if ((size_t)i__1 >= data_size / sizeof(doublereal)) {
        i__1 = (integer)(data_size / sizeof(doublereal)) - 1;
    }

    z__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    vt = (doublereal*)calloc((i__1 + 1) * (vt_dim1 + 1), sizeof(doublereal));
    beta = (doublereal*)malloc(sizeof(doublereal));

    *beta = 1.5;

    for (integer i = nlp2; i <= i__1; ++i) {
        vt[i + nlp2 * vt_dim1] = (doublereal)(i % 100);
    }
}