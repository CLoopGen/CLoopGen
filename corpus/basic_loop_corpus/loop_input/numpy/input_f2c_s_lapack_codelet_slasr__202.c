#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
integer *n;
real *c__;
real *s;
real *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

void init_vars() {
    // Allocate and initialize m and n
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    
    *m = 2000;  // rows
    *n = 1500;  // columns
    
    a_dim1 = *m;  // leading dimension of matrix a
    
    // Allocate arrays c__ and s (size n)
    c__ = (real*)malloc((*n) * sizeof(real));
    s = (real*)malloc((*n) * sizeof(real));
    
    // Allocate 2D matrix a with dimensions m x n
    a = (real*)calloc((*m) * (*n), sizeof(real));
    
    // Initialize matrix a with non-zero values to make computation meaningful
    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j < *n; ++j) {
            a[i + j * a_dim1] = (real)(i + j + 1) / (*m + *n);
        }
    }
    
    // Initialize c__ and s such that some iterations enter the if-block
    for (int j = 0; j < *n - 1; ++j) {
        float angle = (float)j / (*n) * 3.14159f / 4.0f;
        c__[j] = cosf(angle);
        s[j] = sinf(angle);
    }
    // Ensure last element is not accessed beyond bounds
    c__[*n - 1] = 1.0f;
    s[*n - 1] = 0.0f;
    
    // Initialize scalars used in loop
    i__ = 0;
    j = 0;
    temp = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
    i__1 = 0;
}