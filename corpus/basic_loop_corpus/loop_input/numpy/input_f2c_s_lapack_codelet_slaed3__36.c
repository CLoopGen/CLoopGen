#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *q;
integer *indx;
real *w;
integer q_dim1;
integer i__1;
integer j;
integer ii;

void init_vars() {
    // Set problem size to achieve approximately 0.01 seconds runtime
    // Based on typical performance, ~1M iterations gives around 0.01s
    i__1 = 1000000;
    
    // Choose reasonable matrix row size
    q_dim1 = 4;
    
    // Allocate q as a 2D-like array with at least (i__1 x q_dim1) elements
    // We access up to index [j * q_dim1 + 2], so need at least that many
    q = (real*)calloc((i__1 + 1) * (q_dim1 + 1), sizeof(real));
    
    // Allocate and initialize indx array - needs at least 3 elements (indexed from 1)
    indx = (integer*)malloc(3 * sizeof(integer));
    indx[1] = 2;  // ensure valid index for w[]
    
    // Allocate and initialize w array - needs at least 3 elements (indexed from 1)
    w = (real*)malloc(3 * sizeof(real));
    w[1] = 1.0f;
    w[2] = 2.0f;
    
    // Initialize loop counters
    j = 0;
    ii = 0;
}