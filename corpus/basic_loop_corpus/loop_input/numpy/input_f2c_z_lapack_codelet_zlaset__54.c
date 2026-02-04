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
doublecomplex *alpha;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // The loop runs approximately sum_{j=2}^{i__1} min(j-1, *m) iterations
    // We choose values to get about 10M - 50M total iterations for 0.01s on modern CPU
    
    const integer problem_size = 4096;
    
    // Allocate and initialize m
    m = (integer*)malloc(sizeof(integer));
    *m = problem_size;
    
    // Allocate and initialize alpha
    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    alpha->r = 1.0;
    alpha->i = 0.5;
    
    // Set matrix dimensions
    a_dim1 = problem_size;        // leading dimension
    i__1 = problem_size;          // outer loop bound
    
    // Allocate 2D array 'a' as column-major storage
    // Access is a[i + j*a_dim1], so we need space for [a_dim1][?]
    // Maximum index: i__ + j*a_dim1 where i__ <= min(j-1, *m), j <= i__1
    // Max j is i__1 = problem_size, max i__ is problem_size, so max index is problem_size + problem_size*a_dim1
    // = problem_size * (a_dim1 + 1)
    const size_t total_elements = problem_size * (a_dim1 + 1);
    a = (doublecomplex*)calloc(total_elements, sizeof(doublecomplex));
    
    // Initialize loop counters
    i__ = 1;
    i__2 = 1;
    i__3 = 1;
    j = 2;
}