#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    const size_t N = 8000;
    a_dim1 = N;
    b_dim1 = N;
    i__1 = N;
    m = (integer*)malloc(sizeof(integer));
    *m = N;

    size_t total_elements = (size_t)N * N;
    a = (doublereal*)calloc(total_elements, sizeof(doublereal));
    b = (doublereal*)calloc(total_elements, sizeof(doublereal));

    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx] = (doublereal)(idx + 1);
    }
}