#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal psi;
doublereal dpsi;
doublereal temp;
doublereal erretm;

void init_vars() {
    i__1 = 20000000;  

    z__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    delta = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    work = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));

    for (integer i = 1; i <= i__1; ++i) {
        z__[i] = 1.0 + (doublereal)(i % 7);
        delta[i] = 2.0 + (doublereal)(i % 5);
        work[i] = 3.0 + (doublereal)(i % 3);
    }

    psi = 0.0;
    dpsi = 0.0;
    temp = 0.0;
    erretm = 0.0;
}