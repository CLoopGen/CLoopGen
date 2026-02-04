#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
integer i__;
integer j;
real mul;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Empirical tuning: use matrix size around 4000x4000 for reasonable timing
    const int n = 4096;
    
    // Allocate array 'a' as a 2D matrix of size n x n, stored in column-major order
    a = (singlecomplex*)calloc(n * n, sizeof(singlecomplex));
    if (!a) {
        exit(1);
    }
    
    a_dim1 = n;  // leading dimension
    *m = n;      // set m to n
    
    // Set outer loop bound i__1 to n-1 to ensure j+1 <= n
    i__1 = n - 1;
    
    // Initialize mul to a non-zero value
    mul = 2.5f;
    
    // Initialize the matrix with some data to avoid all zeros
    for (int idx = 0; idx < n * n; ++idx) {
        a[idx].r = (real)(idx % 100) * 0.5f;
        a[idx].i = (real)(idx % 101) * 0.25f;
    }
}

// Define m as a pointer to integer, allocate and initialize it
static integer _m_storage;
integer* m = &_m_storage;

// Redefine problematic externs as static globals to allow definition
// (since they are used both as lvalues and rvalues)