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

void init_vars() {
    const int data_size = 8000;
    
    n = (integer*)malloc(sizeof(integer));
    ihi = (integer*)malloc(sizeof(integer));
    *n = data_size;
    *ihi = data_size - 1;
    i__1 = 1;
    
    a_dim1 = *n;
    
    size_t a_size = (size_t)(*n) * (size_t)(*n);
    a = (real*)calloc(a_size, sizeof(real));
    
    if (!n || !ihi || !a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}