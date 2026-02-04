#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int logical;

integer *m;
doublecomplex *alpha;
doublecomplex *a;
doublecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer k;
doublecomplex temp;
logical nounit;

void init_vars() {
    const integer data_size = 1 << 10; 
    m = (integer*)malloc(sizeof(integer));
    *m = data_size;

    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    alpha->r = 1.5;
    alpha->i = 0.5;

    a_dim1 = data_size;
    b_dim1 = data_size;
    i__1 = data_size;

    a = (doublecomplex*)calloc(data_size * data_size, sizeof(doublecomplex));
    b = (doublecomplex*)calloc(data_size * data_size, sizeof(doublecomplex));

    for (integer idx = 0; idx < data_size * data_size; ++idx) {
        a[idx].r = sin(idx % 100);
        a[idx].i = cos(idx % 100);
        b[idx].r = cos(idx % 70) * 0.1;
        b[idx].i = sin(idx % 70) * 0.1;
    }

    nounit = 1;

    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    temp.r = 0.0; temp.i = 0.0;
    i__ = 0;
    j = 0;
    k = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
    i__5 = 0;
}