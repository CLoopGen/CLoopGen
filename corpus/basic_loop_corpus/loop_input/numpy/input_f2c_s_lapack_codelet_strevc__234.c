#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *t;
real *work;
integer t_dim1;
integer i__1;
integer i__2;
real r__1;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve roughly 0.01 seconds runtime
    // Based on typical performance, aim for ~5000x5000 matrix to get sufficient work
    i__1 = 5000;  // outer loop bound (j from 2 to i__1)
    t_dim1 = i__1; // leading dimension of t matrix

    // Allocate t as a 2D matrix in column-major layout: t[i + j*t_dim1]
    t = (real*)calloc(t_dim1 * i__1, sizeof(real));
    if (!t) exit(1);

    // Allocate work vector of size i__1+1 (indexed from 1 to i__1)
    work = (real*)calloc(i__1 + 1, sizeof(real));
    if (!work) exit(1);

    // Initialize t with random positive and negative values to exercise fabsf logic
    for (integer idx = 0; idx < t_dim1 * i__1; ++idx) {
        t[idx] = (real)(rand() % 2000 - 1000) / 100.0f;  // Range ~ [-10.0, 10.0]
    }

    // Ensure the inner loop runs properly: j from 2 to i__1, i from 1 to j-1
    // All memory accesses are within [1, i__1] for rows and columns
}