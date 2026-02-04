#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
integer *n;
doublereal *c__;
doublereal *s;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer j;
doublecomplex temp;
doublereal ctemp;
doublereal stemp;

void init_vars() {
    const integer data_size_mb = 64;
    const integer approx_elements = (data_size_mb * (1 << 20)) / sizeof(doublecomplex);
    const integer n_rows = (integer)sqrt(approx_elements);
    const integer n_cols = approx_elements / n_rows;

    a_dim1 = n_rows;
    i__1 = n_cols > 0 ? n_cols : 1;
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    *m = 1;
    *n = n_rows;

    c__ = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));
    s = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));
    a = (doublecomplex*)malloc((a_dim1 * (*n) + a_dim1 + 1) * sizeof(doublecomplex));

    for (integer idx = 1; idx <= i__1; ++idx) {
        c__[idx] = 0.5 + idx * 0.1;
        s[idx] = 0.1 * idx;
    }

    for (integer i = 1; i <= a_dim1; ++i) {
        for (integer j = 1; j <= *n; ++j) {
            integer idx = j + i * a_dim1;
            if (idx >= 0 && idx < a_dim1 * (*n) + a_dim1 + 1) {
                a[idx].r = (doublereal)(i + j);
                a[idx].i = (doublereal)(i - j);
            }
        }
    }

    i__ = 0;
    j = 0;
    temp.r = 0.0; temp.i = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    z__3.r = 0.0; z__3.i = 0.0;
}