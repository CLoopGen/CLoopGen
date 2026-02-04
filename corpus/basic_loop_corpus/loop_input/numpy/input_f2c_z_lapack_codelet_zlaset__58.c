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
doublecomplex *alpha;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set matrix dimensions and loop bounds
    a_dim1 = 1024;  // leading dimension
    *m = 1024;      // number of rows
    i__1 = a_dim1;  // loop over columns from 1 to i__1
    
    // Allocate alpha
    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    alpha->r = 1.5;
    alpha->i = 0.8;
    
    // Allocate matrix a with size m * a_dim1
    a = (doublecomplex*)calloc((a_dim1 * (*m)) + 1, sizeof(doublecomplex));
}

// Initialize pointers at file scope (can't initialize externs with non-constant expressions at file scope)
static void __attribute__((constructor)) init_pointers() {
    // Allocate m as a global pointer
    static integer m_storage = 0;
    m = &m_storage;
    
    // Call the initialization function
    init_vars();
}