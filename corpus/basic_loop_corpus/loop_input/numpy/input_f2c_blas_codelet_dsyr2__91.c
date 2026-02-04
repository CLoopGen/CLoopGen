#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *alpha;
doublereal *x;
doublereal *y;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp1;
doublereal temp2;

void init_vars() {
    i__1 = 500;  
    a_dim1 = i__1;
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    x = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    y = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    a = (doublereal*)calloc((i__1 + 1) * (a_dim1 + 1), sizeof(doublereal));

    for (j = 1; j <= i__1; ++j) {
        x[j] = (doublereal)(j % 7 != 0 ? 1.0 : 0.0);
        y[j] = (doublereal)(j % 11 != 0 ? 1.5 : 0.0);
    }

    temp1 = 0.0;
    temp2 = 0.0;
    i__ = 0;
    j = 0;
}