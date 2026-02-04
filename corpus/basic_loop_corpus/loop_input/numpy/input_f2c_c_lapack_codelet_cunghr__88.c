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

integer *n;
integer *ihi;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    const int N = 5000;
    
    n = (integer*)malloc(sizeof(integer));
    ihi = (integer*)malloc(sizeof(integer));
    
    *n = N;
    *ihi = N - 1;
    i__1 = 1;
    
    a_dim1 = N;
    
    size_t total_size = (size_t)N * (size_t)N;
    a = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));
    
    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
}