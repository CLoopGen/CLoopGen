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
integer *k;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer j;
integer l;

void init_vars() {
    // Allocate and initialize scalar parameters
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    
    *m = 500;
    *k = 200;
    i__1 = 400;
    a_dim1 = *m + 100;  // Ensure leading dimension is large enough

    // Allocate array 'a' as a 2D matrix with dimensions [a_dim1][i__1+some margin]
    // We access up to index l + j * a_dim1, where l <= *m, j <= i__1
    // So maximum index is (*m) + (i__1) * a_dim1
    ptrdiff_t max_index = (*m) + (i__1) * a_dim1;
    
    // Make sure we allocate at least that many elements
    a = (doublecomplex*)calloc(max_index + 1, sizeof(doublecomplex));
}