#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *c__;
real *s;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, choose n around 1000-2000 for reasonable timing
    int n_val = 1500;
    
    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = n_val;
    
    // Set i__1 to n (common in Fortran-style loops)
    i__1 = *n;
    
    // Set matrix dimensions
    a_dim1 = *n;  // leading dimension
    
    // Allocate arrays with appropriate sizes
    c__ = (real*)calloc(*n, sizeof(real));
    s = (real*)calloc(*n, sizeof(real));
    a = (real*)calloc((*n + 1) * (a_dim1 + 1), sizeof(real));  // 1-based indexing emulation
    
    // Initialize c__ and s arrays with meaningful values
    // Ensure some iterations enter the if condition (ctemp != 1 || stemp != 0)
    for (int idx = 0; idx < *n; idx++) {
        // Use sinusoidal pattern to ensure variety
        c__[idx] = (real)cos((idx + 1) * 0.1);
        s[idx] = (real)sin((idx + 1) * 0.1);
    }
    
    // Initialize matrix a with non-zero values to make computation meaningful
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= *n; j++) {
            a[j + i * a_dim1] = (real)(i * 0.01);
        }
    }
    
    // Initialize temp variables to zero
    temp = 0.0f;
    ctemp = 1.0f;
    stemp = 0.0f;
}