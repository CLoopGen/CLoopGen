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
doublereal *rwork;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical CPU speed, aim for moderate data size: ~16-32 million elements
    const int M = 4096;  // *m
    const int N = 4096;  // i__1 (j <= N)

    // Allocate memory for m (scalar)
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    // Set a_dim1 to leading dimension of matrix 'a', typically >= *m
    a_dim1 = M;

    // i__1 is loop bound for j, set to N
    i__1 = N;

    // Total elements in matrix a: a_dim1 x N (column-major assumed)
    int a_size = a_dim1 * N;
    a = (doublecomplex*)calloc(a_size, sizeof(doublecomplex));
    if (!a) exit(1);

    // rwork size: (j-1)*M + i__, max index when j=N, i__=M -> (N-1)*M + M = N*M
    int rwork_size = N * M;
    rwork = (doublereal*)calloc(rwork_size, sizeof(doublereal));
    if (!rwork) exit(1);

    // Initialize a with non-zero values to allow meaningful copying
    for (int idx = 0; idx < a_size; ++idx) {
        a[idx].r = (doublereal)(idx + 1);
        a[idx].i = (doublereal)(-(idx + 1));
    }

    // Ensure all loop indices are initialized to safe values
    i__2 = *m;
    i__3 = 1;
    i__ = 1;
    j = 1;
}