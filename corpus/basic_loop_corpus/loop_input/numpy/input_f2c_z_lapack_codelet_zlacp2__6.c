#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublereal *a;
doublecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M elements, adjust as needed for timing
    const integer matrix_size = 1000;

    m = (integer*)malloc(sizeof(integer));
    *m = matrix_size;

    a_dim1 = matrix_size;
    b_dim1 = matrix_size;
    i__1 = matrix_size;

    a = (doublereal*)calloc(data_size, sizeof(doublereal));
    b = (doublecomplex*)calloc(data_size, sizeof(doublecomplex));

    if (!a || !b || !m) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        a[idx] = (doublereal)(idx % 1000);
    }
}