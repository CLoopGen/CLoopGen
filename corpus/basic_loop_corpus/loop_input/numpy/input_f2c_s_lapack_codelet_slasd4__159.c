#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer i__1 = 2097152;  // Size: ~8MB for d__ and work (each float array of size 2^21), total ~16MB data
integer *i__ = NULL;
real *d__ = NULL;
real *delta = NULL;
real *work = NULL;
integer j;
real eta = 1.5f;

void init_vars() {
    // Allocate arrays with size i__1 + 1 to accommodate 1-based indexing (j from 1 to i__1)
    d__ = (real*)calloc(i__1 + 1, sizeof(real));
    work = (real*)calloc(i__1 + 1, sizeof(real));
    delta = (real*)calloc(i__1 + 1, sizeof(real));
    i__ = (integer*)malloc(sizeof(integer));
    
    if (!d__ || !work || !delta || !i__) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    *i__ = i__1;  // Set *i__ to valid index within bounds (e.g., last element)

    // Initialize d__ with sample values to avoid NaNs or undefined behavior
    for (integer idx = 1; idx <= i__1; ++idx) {
        d__[idx] = sinf((real)idx);
    }

    eta = 1.5f;  // Reaffirm eta value
}