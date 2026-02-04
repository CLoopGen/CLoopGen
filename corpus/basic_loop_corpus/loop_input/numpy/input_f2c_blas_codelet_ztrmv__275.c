#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;
typedef int logical;

doublecomplex *a = NULL;
doublecomplex *x = NULL;
integer *incx = NULL;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer ix;
integer jx;
integer kx;
doublecomplex temp;
logical nounit;

void init_vars() {
    const int size = 4096;
    const int matrix_size = size * size;
    const int vector_size = size;

    a = (doublecomplex*)calloc(matrix_size, sizeof(doublecomplex));
    x = (doublecomplex*)calloc(vector_size, sizeof(doublecomplex));
    incx = (integer*)malloc(sizeof(integer));

    if (!a || !x || !incx) {
        exit(1);
    }

    *incx = 1;
    a_dim1 = size;
    i__1 = size;
    jx = 0;
    kx = 0;
    nounit = 1;

    for (int idx = 0; idx < vector_size; ++idx) {
        x[idx].r = sin(idx);
        x[idx].i = cos(idx);
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int idx = col + row * a_dim1;
            a[idx].r = (doublereal)(sin((row + col) * 0.1));
            a[idx].i = (doublereal)(cos((row + col) * 0.1));
        }
    }
}