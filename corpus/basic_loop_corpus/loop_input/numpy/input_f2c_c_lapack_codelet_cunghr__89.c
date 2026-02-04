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

integer *n;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to ensure ~0.01 seconds runtime
    // Assume matrix of size N x N, and total operations ~ N^2
    // On modern CPU, aim for ~10-100 million operations -> N ~ 10000 gives 100M elements
    // But we write to N*M + N elements (M = i__1), so set M = 1000, N = 1000 -> 1e6 operations

    const int N = 1000;   // *n = N
    const int M = 1000;   // i__1 = M

    // Allocate space for matrix A: (N+1) x (M+1) to allow 1-based indexing
    a_dim1 = N;  // leading dimension
    n = (integer*)malloc(sizeof(integer));
    *n = N;

    i__1 = M;

    // Allocate A: index up to i + j*a_dim1 => max index is N + M*a_dim1
    // We need at least M * a_dim1 + N + 1 elements
    size_t alloc_size = (M + 1) * (a_dim1 + 1);
    a = (singlecomplex*)calloc(alloc_size, sizeof(singlecomplex));
    if (!a) exit(1);

    // Initialize scalars used in loops
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
}