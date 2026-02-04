#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
integer *n;
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
    const int size_m = 1000;
    const int size_n = 1000;

    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));

    *m = size_m;
    *n = size_n;
    *alpha = 1.2;

    a_dim1 = size_m;
    b_dim1 = size_m;

    size_t a_size = (size_t)size_m * size_n * sizeof(doublereal);
    size_t b_size = (size_t)size_m * size_n * sizeof(doublereal);

    a = (doublereal*)malloc(a_size);
    b = (doublereal*)malloc(b_size);

    for (int i = 0; i < size_m * size_n; ++i) {
        a[i] = sin(i % 100 + 1.0);
        b[i] = cos(i % 100 + 1.0);
    }

    nounit = 1;

    i__ = 0;
    j = 0;
    k = 0;
    i__1 = 0;
    i__2 = 0;
    temp = 0.0;
}