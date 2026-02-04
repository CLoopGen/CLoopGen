#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *beta;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    // Allocate beta as a single complex value
    beta = (singlecomplex*)malloc(sizeof(singlecomplex));
    beta->r = 1.0f;
    beta->i = 0.5f;

    // Set problem size to target ~0.01 seconds runtime
    // Assume modern CPU can do ~1e8 operations/sec, so aim for ~1e6 iterations
    i__1 = 1000;  // Controls loop count: i__ from 1 to i__1
    a_dim1 = 1000; // So that i__ + i__ * a_dim1 is within bounds

    // Total size needed: indices go up to i__1 + i__1 * a_dim1 = 1000 + 1000*1000 = 1001000
    ptrdiff_t total_size = (i__1 + 1) * (a_dim1 + 1); // Use safe upper bound
    a = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));
}