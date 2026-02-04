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

integer *n;
doublecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical testing suggests n around 4000-5000 gives appropriate duration
    // We'll use n = 4634 -> total elements ~ (n^2)/2 ≈ 10.7M, with 16 bytes per complex = ~171MB touched

    const integer problem_size = 4634;
    
    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = problem_size;

    // Set loop bound i__1 to be equal to *n to ensure valid range
    i__1 = *n;

    // Set leading dimension to *n (column-major assumed)
    c_dim1 = *n;

    // Allocate 2D array c__[1..*n][1..*n], stored column-major
    c__ = (doublecomplex*)calloc((*n + 1) * (c_dim1 + 1), sizeof(doublecomplex));
    // Indexing uses 1-based indexing: j from 1 to i__1, i__ from j to *n
    // So we need space up to index [*n][*n] -> allocate (*n+1) * (c_dim1+1)
}

// DO NOT include main(), headers, explanations or comments below this line