#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float real;
typedef int integer;

real *d__ = NULL;
integer *indxq = NULL;
real *dlamda = NULL;
integer *perm = NULL;
integer *indxp = NULL;
integer *indx = NULL;
integer i__1;
integer j;
integer jp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million elements for ~256MB total (adjust for float/int sizes)
    i__1 = (integer)(data_size / sizeof(real)); // Set loop count to avoid overflow, ~64M/4 = 16M

    // Allocate arrays
    d__ = (real*)calloc(i__1 + 1, sizeof(real));
    dlamda = (real*)calloc(i__1 + 1, sizeof(real));
    indxp = (integer*)calloc(i__1 + 1, sizeof(integer));
    indx = (integer*)calloc(i__1 + 1, sizeof(integer));
    perm = (integer*)calloc(i__1 + 1, sizeof(integer));
    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));

    // Initialize index arrays to valid ranges to prevent out-of-bounds access
    for (j = 1; j <= i__1; ++j) {
        indxp[j] = j;
        indx[j] = j % i__1;
        if (indx[j] == 0) indx[j] = 1;
        indxq[j] = j;
        d__[j] = (real)(rand() % 1000) / 10.0f;
    }

    // Ensure indxq is safe for perm[j] = indxq[indx[jp]]
    for (j = 1; j <= i__1; ++j) {
        if (indx[j] > i__1) indx[j] = 1;
    }
}