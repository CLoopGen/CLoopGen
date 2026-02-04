#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

void init_vars() {
    const int size = 1000;

    m = (integer*)malloc(sizeof(integer));
    *m = size;

    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    a_dim1 = size;
    b_dim1 = size;

    i__1 = size;
    nounit = 1;

    a = (doublereal*)calloc(size * size, sizeof(doublereal));
    b = (doublereal*)calloc(size * size, sizeof(doublereal));

    for (int idx = 0; idx < size; ++idx) {
        a[idx + idx * a_dim1] = 2.0;
        for (int jdx = idx + 1; jdx < size; ++jdx) {
            a[jdx + idx * a_dim1] = (doublereal)(rand()) / RAND_MAX * 2.0 - 1.0;
        }
    }

    for (int idx = 0; idx < size; ++idx) {
        for (int jdx = 0; jdx < size; ++jdx) {
            b[idx + jdx * b_dim1] = (doublereal)(rand()) / RAND_MAX * 2.0 - 1.0;
        }
    }
}