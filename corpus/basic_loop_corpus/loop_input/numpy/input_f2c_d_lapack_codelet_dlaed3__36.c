#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *q;
integer *indx;
doublereal *w;
integer q_dim1;
integer i__1;
integer j;
integer ii;

void init_vars() {
    const size_t target_size = 128 * 1024 * 1024; // Aim for ~128MB of data
    const size_t element_size = sizeof(doublereal);
    
    // Estimate total elements to allocate based on q as the largest structure
    // q is accessed as q[j * q_dim1 + offset], so it's a 2D array with first dimension q_dim1
    // We assume q has at least 3 columns and several rows
    q_dim1 = 3; // Enough for indices 1,2 used in loop (1-indexed)
    i__1 = (target_size / (q_dim1 * element_size)) + 10; // Number of rows we'll iterate over

    // Allocate q: (i__1 + 1) x (q_dim1 + 1) to safely access index [j * q_dim1 + 2]
    q = (doublereal*)calloc((i__1 + 1) * (q_dim1 + 1), sizeof(doublereal));
    
    // Allocate w with at least 3 elements (used as 1-indexed up to index 2)
    w = (doublereal*)calloc(3, sizeof(doublereal));
    
    // indx needs at least 3 elements (accessed by indx[1], indx[2])
    indx = (integer*)calloc(3, sizeof(integer));
    
    // Initialize w with dummy values
    w[1] = 1.1;
    w[2] = 2.2;
    
    // Initialize q with non-zero values to make swaps observable
    for (integer row = 1; row <= i__1; ++row) {
        q[row * q_dim1 + 1] = row + 0.1;
        q[row * q_dim1 + 2] = row + 0.2;
        q[row * q_dim1 + 3] = row + 0.3;
    }
    
    // Set up indx mapping: swap elements 1 and 2
    indx[1] = 2; // So w[ii] where ii=indx[1] will be w[2]
    indx[2] = 1; // So w[ii] where ii=indx[2] will be w[1]
    
    // Initialize loop counters
    j = 1;
    ii = 1;
}