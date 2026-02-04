#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
integer *ihi;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

static real *a_data = NULL;
static integer n_val;
static integer ihi_val;

void init_vars() {
    n_val = 5000;
    ihi_val = 1000;
    i__1 = 2000;
    a_dim1 = n_val;
    
    n = &n_val;
    ihi = &ihi_val;
    
    size_t a_size = (size_t)n_val * (size_t)(i__1 + 1);
    a_data = (real*)calloc(a_size, sizeof(real));
    if (!a_data) {
        exit(1);
    }
    a = a_data;
}