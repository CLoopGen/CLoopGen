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

typedef int logical;

integer *n;
doublecomplex *a;
doublecomplex *x;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
doublecomplex temp;
logical nounit;

static integer n_val;
static doublecomplex *a_data;
static doublecomplex *x_data;

void init_vars() {
    n_val = 2048;
    n = &n_val;

    a_dim1 = n_val;
    size_t a_size = (size_t)(n_val + 1) * (size_t)(n_val + 1);
    a_data = (doublecomplex*)calloc(a_size, sizeof(doublecomplex));
    if (!a_data) exit(1);
    a = a_data;

    size_t x_size = (size_t)(n_val + 1);
    x_data = (doublecomplex*)calloc(x_size, sizeof(doublecomplex));
    if (!x_data) exit(1);
    x = x_data;

    nounit = 1;

    for (int idx = 1; idx <= n_val; ++idx) {
        x[idx].r = 1.0 / idx;
        x[idx].i = -1.0 / (idx + 1);
    }

    for (int row = 1; row <= n_val; ++row) {
        for (int col = 1; col <= n_val; ++col) {
            if (col <= row) {
                a[row + col * a_dim1].r = 0.1 * ((row + col) % 7 - 3);
                a[row + col * a_dim1].i = 0.1 * ((row - col) % 5 - 2);
            }
        }
    }

    i__ = 0;
    j = 0;
    temp.r = 0.0; temp.i = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    i__1 = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
}