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

integer *n;
doublecomplex *b;
doublereal *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
integer jcol;
integer jrow;
integer jimag;
integer jreal;

void init_vars() {
    const integer data_size = 1 << 20; // 1M elements for ~1MB-256MB range
    const integer matrix_dim = 1000;   // b will be 1000 x 1000

    n = (integer*)malloc(sizeof(integer));
    *n = matrix_dim;

    b_dim1 = matrix_dim;
    i__1 = matrix_dim; // outer loop bound

    b = (doublecomplex*)calloc((matrix_dim + 1) * (matrix_dim + 1), sizeof(doublecomplex));

    const integer rwork_size = 2 * matrix_dim * matrix_dim + 10;
    rwork = (doublereal*)malloc(rwork_size * sizeof(doublereal));
    for (integer i = 0; i < rwork_size; ++i) {
        rwork[i] = (doublereal)(i % 100) / 10.0;
    }

    jreal = 0;
    jimag = matrix_dim * matrix_dim;
}