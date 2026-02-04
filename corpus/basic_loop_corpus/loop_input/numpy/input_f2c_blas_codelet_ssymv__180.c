#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

real *alpha;
real *a;
real *x;
integer *incx;
real *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer iy;
integer jx;
integer jy;
integer kx;
integer ky;
real temp1;
real temp2;

static real alpha_data;
static real *a_data;
static real *x_data;
static real *y_data;
static integer incx_data;
static integer incy_data;

void init_vars() {
    // Problem size parameters
    const integer n = 4096;  // Approximate size for desired runtime
    
    // Initialize scalar variables
    alpha_data = 1.5f;
    alpha = &alpha_data;
    
    incx_data = 1;
    incx = &incx_data;
    
    incy_data = 1;
    incy = &incy_data;
    
    a_dim1 = n;
    i__1 = n;
    
    // Allocate arrays
    a_data = (real*)calloc(n * n, sizeof(real));
    x_data = (real*)calloc(n, sizeof(real));
    y_data = (real*)calloc(n, sizeof(real));
    
    if (!a_data || !x_data || !y_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize data
    for (integer i = 0; i < n; ++i) {
        x_data[i] = 1.0f + i % 7;
        y_data[i] = 2.0f + i % 13;
        for (integer j = 0; j < n; ++j) {
            a_data[i + j * a_dim1] = (i == j) ? 2.0f : ((i < j) ? 0.1f : 0.05f);
        }
    }
    
    // Set pointers
    a = a_data;
    x = x_data;
    y = y_data;
    
    // Initialize indexing variables
    kx = 1;
    ky = 1;
    jx = 1;
    jy = 1;
    
    // Initialize temporaries
    temp1 = 0.0f;
    temp2 = 0.0f;
}