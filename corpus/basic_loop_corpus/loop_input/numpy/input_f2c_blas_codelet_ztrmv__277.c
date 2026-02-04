#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
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
    const int N = 4096;  // Problem size chosen to yield ~tens of milliseconds runtime

    // Allocate and initialize scalar parameters
    n = (integer*)malloc(sizeof(integer));
    *n = N;

    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    a_dim1 = N;  // leading dimension of matrix 'a'

    nounit = 1;  // can be true (1) or false (0); using 1 for safety

    // Allocate matrix A: triangular NxN stored in column-major order, size N*N
    a = (doublecomplex*)calloc(N * N, sizeof(doublecomplex));
    // Initialize upper triangular part with non-zero values to ensure computation happens
    for (int col = 0; col < N; ++col) {
        for (int row = 0; row <= col; ++row) {
            a[row + col * a_dim1].r = sin((row + 1) * (col + 1)) * 0.01;
            a[row + col * a_dim1].i = cos((row + 1) * (col + 1)) * 0.01;
        }
    }

    // Allocate vector X of size N
    x = (doublecomplex*)calloc(N, sizeof(doublecomplex));
    // Initialize with some data on the diagonal positions that will be accessed
    for (int i = 0; i < N; ++i) {
        x[i].r = (doublereal)(i % 7);
        x[i].i = (doublereal)(i % 11);
    }

    // Initialize loop indices
    kx = N - 1;      // starting index for x when traversed backward
    jx = N - 1;      // start jx at last element

    // Ensure temp is zero
    temp.r = 0.0;
    temp.i = 0.0;

    // Initialize temporaries used in expressions
    i__ = 0;
    j = 0;
    ix = 0;
    i__1 = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
}