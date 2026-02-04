#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *alpha;
real *a;
real *x;
real *y;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp1;
real temp2;

#define DATA_SIZE 2048

void init_vars() {
    // Allocate and initialize scalar variables
    n = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    *n = DATA_SIZE;
    *alpha = 1.5f;
    
    // Set loop bound i__1 to be within array size
    i__1 = (*n > 1000) ? 1000 : *n;  // Limit outer loop for predictable runtime
    
    // Allocate arrays with appropriate sizes
    x = (real*)calloc(*n + 1, sizeof(real));  // 1-based indexing
    y = (real*)calloc(*n + 1, sizeof(real));
    
    a_dim1 = *n;
    // Allocate 2D array a as column-major: [1..n][1..n]
    a = (real*)calloc((*n + 1) * (*n + 1), sizeof(real));
    
    // Initialize arrays with non-zero values to avoid trivial optimization
    for (int idx = 1; idx <= *n; ++idx) {
        x[idx] = sinf(idx);
        y[idx] = cosf(idx);
    }
    
    for (int row = 1; row <= *n; ++row) {
        for (int col = 1; col <= *n; ++col) {
            a[row + col * a_dim1] = (real)(sin(row) * cos(col));
        }
    }
}