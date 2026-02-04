#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *n;
real *a;
real *x;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer jx;
real temp;
logical nounit;

#define A_ROWS 1024
#define A_COLS 1024
#define X_SIZE 1024

static real a_data[A_ROWS * A_COLS];
static real x_data[X_SIZE];
static integer n_val;
static integer incx_val;

void init_vars() {
    n_val = X_SIZE;
    n = &n_val;
    
    incx_val = 1;
    incx = &incx_val;
    
    a_dim1 = A_ROWS;
    i__1 = (A_COLS < X_SIZE) ? A_COLS : X_SIZE;
    nounit = 1;
    
    a = a_data;
    x = x_data;
    
    jx = 0;
    
    for (int i = 0; i < A_ROWS; ++i) {
        for (int j = 0; j < A_COLS; ++j) {
            a[i + j * a_dim1] = (real)(rand() % 100) / 50.0f - 1.0f;
        }
    }
    
    for (int i = 0; i < X_SIZE; ++i) {
        x[i] = (real)(rand() % 100) / 50.0f - 1.0f;
    }
}