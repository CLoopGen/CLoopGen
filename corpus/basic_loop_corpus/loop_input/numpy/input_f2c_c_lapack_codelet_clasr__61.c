#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
integer *n;
real *c__;
real *s;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;
integer i__;
integer j;
singlecomplex temp;
real ctemp;
real stemp;

void init_vars() {
    // Allocate and initialize m and n
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    *m = 500;
    *n = 500;

    // Allocate arrays c__ and s of size at least max(*m, *n) to avoid out-of-bounds
    c__ = (real*)calloc(*m + 10, sizeof(real));
    s   = (real*)calloc(*m + 10, sizeof(real));

    // Initialize c__ and s: set c__[j] != 1 or s[j] != 0 for many j to ensure loop body runs
    for (int j = 1; j <= *m; ++j) {
        c__[j] = (j % 3 == 0) ? 1.0f : 0.8f;
        s[j] = (j % 3 == 0) ? 0.0f : 0.6f;
    }

    // Set matrix dimensions and allocate 'a' with dimensions [a_dim1][*n], indexed as j + i*a_dim1
    a_dim1 = *m + 10;  // leading dimension, must be >= *m+1
    a = (singlecomplex*)calloc((a_dim1 + 1) * (*n + 1), sizeof(singlecomplex));

    // Initialize a matrix with some data to prevent undefined behavior during access
    for (int i = 1; i <= *n; ++i) {
        for (int j = 1; j <= *m + 1; ++j) {
            int idx = j + i * a_dim1;
            a[idx].r = (real)(i % 7 + j % 5);
            a[idx].i = (real)(i % 3 - j % 4);
        }
    }

    // Initialize temporaries to zero
    temp.r = 0.0f; temp.i = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
    q__1.r = q__1.i = 0.0f;
    q__2.r = q__2.i = 0.0f;
    q__3.r = q__3.i = 0.0f;
    i__ = 0;
    j = 0;
    i__1 = i__2 = i__3 = 0;
}