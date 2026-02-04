#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *q = NULL;
integer q_dim1 = 0;
integer i__1 = 0;
integer i__ = 0;
integer ktemp = 0;

void init_vars() {
    // Set dimensions and parameters
    q_dim1 = 1024;          // Leading dimension of q
    ktemp = 5;              // Offset multiplier
    i__1 = q_dim1;          // Loop bound: ensures we don't exceed row size

    // Allocate 2D array as a linear block to avoid padding issues
    // Access pattern: q[i + j * q_dim1] => treat as column-major matrix
    // We need at least max(i + ktemp * q_dim1) + 1 elements
    integer required_size = i__1 + ktemp * q_dim1 + 1;

    q = (doublereal*)calloc(required_size, sizeof(doublereal));
    if (!q) {
        exit(1);
    }

    // Initialize source region to have valid data
    for (integer i = 1; i <= i__1; ++i) {
        q[i + q_dim1] = (doublereal)(i & 0xFF); // arbitrary non-zero initialization
    }
}