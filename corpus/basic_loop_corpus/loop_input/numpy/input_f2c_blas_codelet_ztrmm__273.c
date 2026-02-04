#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int logical;

integer *m;
integer *n;
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
integer i__6;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer k;
doublecomplex temp;
logical nounit;

void init_vars() {
    // Allocate scalar integers
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    
    // Set matrix dimensions
    *m = 512;   // rows of matrix b
    *n = 512;   // cols of matrix a and b
    a_dim1 = *n; // leading dimension of a
    b_dim1 = *m; // leading dimension of b
    i__1 = *n;   // outer loop bound: j <= i__1

    // Allocate and initialize alpha
    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    alpha->r = 1.5;
    alpha->i = 0.5;

    // Allocate matrices a and b as column-major arrays
    a = (doublecomplex*)calloc(a_dim1 * (*n), sizeof(doublecomplex));
    b = (doublecomplex*)calloc(b_dim1 * (*n), sizeof(doublecomplex));

    // Initialize b with non-zero values to make computation meaningful
    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j < *n; ++j) {
            int idx = i + j * b_dim1;
            b[idx].r = (doublereal)(i + j) / (*m + *n);
            b[idx].i = (doublereal)(i - j) / (*m + *n);
        }
    }

    // Initialize a with random-like non-zero pattern (lower triangle)
    for (int j = 0; j < *n; ++j) {
        for (int k = j; k < *n; ++k) {
            int idx = k + j * a_dim1;
            a[idx].r = (k == j) ? 1.0 : ((double)rand() / RAND_MAX);
            a[idx].i = (k == j) ? 0.0 : ((double)rand() / RAND_MAX) * 0.5;
        }
    }

    // Default working variables
    nounit = 1;  // false: unit diagonal (skip multiplication on diagonal)

    // Seed temp to zero
    temp.r = 0.0;
    temp.i = 0.0;

    // Ensure consistent behavior for temporaries
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    i__ = 0; j = 0; k = 0;
}