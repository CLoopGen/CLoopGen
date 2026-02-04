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
singlecomplex *alpha;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set matrix dimensions and loop bounds
    const int M = 8000;  // rows
    const int N = 8000;  // columns

    // Allocate and initialize m
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    // Allocate and initialize alpha
    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    alpha->r = 1.0f;
    alpha->i = 0.5f;

    // Allocate 2D array 'a' with dimensions [M+1][N+1] (1-indexed, so we use indices 1..M, 1..N)
    a_dim1 = M;
    a = (singlecomplex*)calloc((M + 1) * (N + 1), sizeof(singlecomplex));

    // Set loop bound i__1 = N (since j runs from 1 to N)
    i__1 = N;

    // Initialize other external temporaries to safe values
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
}