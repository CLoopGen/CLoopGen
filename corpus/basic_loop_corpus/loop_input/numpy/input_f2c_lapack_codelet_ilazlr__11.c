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
doublecomplex *a;
integer a_dim1;
integer ret_val;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Set matrix dimensions
    const integer M = 4096;  // rows
    const integer N = 4096;  // columns

    // Allocate memory for m (single integer)
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    // Allocate 2D array 'a' with dimensions [M+1][N+1] (1-indexed, so we use 1..M, 1..N)
    a_dim1 = M;
    a = (doublecomplex*)calloc((M + 1) * (N + 1), sizeof(doublecomplex));

    // Initialize loop bounds
    i__1 = N;  // j runs from 1 to i__1 (columns)
    ret_val = 0;

    // Ensure non-zero elements exist near the bottom of each column to control inner loop behavior
    for (j = 1; j <= i__1; ++j) {
        // Place a non-zero element somewhere in the lower part of each column
        i__ = M - (j % 10);  // avoid exactly M to allow some decrements
        if (i__ >= 1 && i__ <= M) {
            a[i__ + j * a_dim1].r = 1.0;
            a[i__ + j * a_dim1].i = 1.0;
        }
    }

    // Initialize loop indices
    i__ = 0;
    j = 0;
    i__2 = 0;
}