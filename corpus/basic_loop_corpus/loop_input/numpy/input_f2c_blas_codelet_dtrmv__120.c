#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;
typedef int logical;

doublereal *a;
doublereal *x;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp;
logical nounit;

void init_vars() {
    const int size = 5000;
    a_dim1 = size;
    i__1 = size;

    a = (doublereal*)calloc(size * size, sizeof(doublereal));
    x = (doublereal*)malloc(size * sizeof(doublereal));

    for (int idx = 0; idx < size; ++idx) {
        x[idx] = idx % 2 ? 1.5 : 0.0;
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            a[row + col * a_dim1] = sin(row * col) + 1.0;
        }
    }

    nounit = 1;
    temp = 0.0;
    i__ = 0;
    j = 0;
}