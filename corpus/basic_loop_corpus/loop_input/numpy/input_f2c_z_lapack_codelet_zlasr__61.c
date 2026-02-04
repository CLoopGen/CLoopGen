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
integer *n;
doublereal *c__;
doublereal *s;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer j;
doublecomplex temp;
doublereal ctemp;
doublereal stemp;

void init_vars() {
    // Allocate and initialize m and n
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    *m = 500;   // Set m to 500 so that j goes from m-1 down to 1
    *n = 1000;  // Set n to 1000 for inner loop bound

    // Allocate arrays c__ and s of size at least *m
    c__ = (doublereal*)calloc(*m, sizeof(doublereal));
    s = (doublereal*)calloc(*m, sizeof(doublereal));

    // Initialize c__ and s: set all to (1.0, 0.0) except a few to trigger the if-body
    for (int idx = 0; idx < *m; ++idx) {
        c__[idx] = 1.0;
        s[idx] = 0.0;
    }
    // Modify some values to ensure the condition (ctemp != 1. || stemp != 0.) is sometimes true
    c__[1] = 0.8;
    s[1] = 0.6;

    // Set leading dimension and allocate a as a column-major 2D array: dimensions [*m][*n]
    a_dim1 = *m;  // leading dimension
    a = (doublecomplex*)calloc(a_dim1 * (*n), sizeof(doublecomplex));

    // Initialize a with sample data
    for (int col = 0; col < *n; ++col) {
        for (int row = 0; row < *m; ++row) {
            int idx = row + col * a_dim1;
            a[idx].r = (doublereal)(row + 1);
            a[idx].i = (doublereal)(col + 1);
        }
    }

    // Initialize temporaries to zero
    temp.r = 0.0; temp.i = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    z__3.r = 0.0; z__3.i = 0.0;
    i__ = 0;
    j = 0;
    i__1 = 0;
    i__2 = 0;
    i__3 = 0;
}