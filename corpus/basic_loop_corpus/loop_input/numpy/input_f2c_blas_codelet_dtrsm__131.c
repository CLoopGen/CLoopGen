#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

void init_vars() {
    // Set matrix dimensions
    const int M = 500;   // *m = number of rows
    const int N = 500;   // i__1 = number of columns in B

    // Allocate and initialize scalar m
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    // Allocate and initialize alpha
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    // Set leading dimensions (row strides)
    a_dim1 = M;
    b_dim1 = M;

    // Allocate matrices A and B with appropriate sizes (M x M for A, M x N for B)
    a = (doublereal*)calloc(M * M, sizeof(doublereal));
    b = (doublereal*)calloc(M * N, sizeof(doublereal));

    // Initialize A as lower triangular with non-zero diagonals
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j <= i; ++j) {
            a[j + i * a_dim1] = (doublereal)(i == j ? 2.0 : 0.1);  // diagonal dominant
        }
    }

    // Initialize B with random-like values
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            b[i + j * b_dim1] = (doublereal)(i + j + 1) / (M + N);
        }
    }

    // Loop bounds
    i__1 = N;  // outer loop over j from 1 to N
    nounit = 1; // false: use division by diagonal; set to true (non-zero) to enable division

    // Ensure temp is initialized
    temp = 0.0;
}