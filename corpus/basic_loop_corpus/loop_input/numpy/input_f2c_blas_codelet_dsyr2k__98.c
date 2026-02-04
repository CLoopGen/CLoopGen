#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *beta;
doublereal *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical testing suggests n around 4000 gives reasonable timing
    const integer problem_size = 4096;
    
    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = problem_size;
    
    // Allocate and initialize beta
    beta = (doublereal*)malloc(sizeof(doublereal));
    *beta = 1.5;
    
    // Set leading dimension and loop bounds
    c_dim1 = *n;
    i__1 = *n;  // j goes from 1 to n
    
    // Allocate c__ as a 2D matrix in column-major order: (n+1) x (n+1), 1-indexed
    // We use 1-based indexing, so allocate extra space
    c__ = (doublereal*)calloc((problem_size + 1) * (problem_size + 1), sizeof(doublereal));
    
    // Initialize matrix with non-zero values to make scaling visible
    for (integer col = 1; col <= *n; ++col) {
        for (integer row = 1; row <= *n; ++row) {
            c__[row + col * c_dim1] = (doublereal)(row + col);
        }
    }
    
    // Initialize loop indices to safe values
    i__ = 1;
    j = 1;
    i__2 = *n;
}