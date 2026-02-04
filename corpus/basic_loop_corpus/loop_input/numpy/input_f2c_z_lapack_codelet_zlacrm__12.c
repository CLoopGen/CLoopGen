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
doublecomplex *c__;
doublereal *rwork;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;
integer l;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Empirical tuning: aim for about 1M elements as a base
    const integer M = 1024;   // *m = number of rows
    const integer N = 1024;   // i__1 = number of columns

    // Allocate and initialize m
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    // Set c_dim1 to leading dimension of c__, must be >= *m
    c_dim1 = M;

    // Set number of columns to process
    i__1 = N;

    // Set l offset: ensure it's valid for indexing rwork
    // l + (j-1)*(*m) + i__ - 1 < size of rwork
    // Max index: l + (N-1)*M + M - 1 = l + N*M - 1
    // So we need rwork size >= l + N*M
    // Let l = 0 for safety
    l = 0;

    // Total required size for rwork: l + N*M + padding = N*M
    const size_t rwork_size = (size_t)N * M;
    rwork = (doublereal*)calloc(rwork_size, sizeof(doublereal));
    if (!rwork) exit(1);

    // Initialize rwork with some data
    for (size_t idx = 0; idx < rwork_size; ++idx) {
        rwork[idx] = (doublereal)(idx + 1);
    }

    // Allocate c__ array: at least c_dim1*N elements
    const size_t c_size = (size_t)c_dim1 * N;
    c__ = (doublecomplex*)calloc(c_size, sizeof(doublecomplex));
    if (!c__) exit(1);

    // Initialize loop indices used inside (will be overwritten in loop)
    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
}