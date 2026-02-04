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
singlecomplex *b;
real *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer j;
integer jcol;
integer jrow;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Empirical tuning: use matrix of size 4096 x 4096 -> ~67M elements accessed, fits in 100-200ms range
    // Adjust down to ~2048 x 2048 for ~16M iterations -> likely within 0.01s on modern CPU

    const int N = 2048;
    const int M = 2048;

    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = N;

    // Allocate b as 2D array with leading dimension b_dim1
    b_dim1 = N;  // leading dimension
    b = (singlecomplex*)calloc((size_t)(b_dim1 * M), sizeof(singlecomplex));

    // i__1 is upper bound for jcol -> set to M
    i__1 = M;

    // rwork must be large enough: total number of loop iterations is M * N
    rwork = (real*)malloc((size_t)(M * N + 1) * sizeof(real)); // +1 for safety due to ++j indexing
    j = 0; // initial value of j; will be incremented before use

    // Initialize other loop indices to safe values
    jcol = 0;
    jrow = 0;
    i__2 = 0;
    i__3 = 0;

    // Ensure all memory is touched to avoid lazy allocation faults
    for (int i = 0; i < M * N; ++i) {
        rwork[i] = 0.0f;
    }
    for (int i = 0; i < b_dim1 * M; ++i) {
        b[i].r = (real)(i);
        b[i].i = (real)(-i);
    }
}