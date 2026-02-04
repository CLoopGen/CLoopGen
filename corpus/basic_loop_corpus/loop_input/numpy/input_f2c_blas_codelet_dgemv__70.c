#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *x;
doublereal *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer jy;
doublereal temp;

#define M_SIZE 2000
#define N_SIZE 150

void init_vars() {
    // Allocate and initialize scalar variables
    m = (integer*)malloc(sizeof(integer));
    *m = M_SIZE;
    
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;
    
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;
    
    // Set problem dimensions
    i__1 = N_SIZE;  // number of columns in A, length of y to update
    
    a_dim1 = M_SIZE; // leading dimension of matrix a
    
    // Allocate arrays
    size_t a_size = (size_t)M_SIZE * N_SIZE;
    a = (doublereal*)calloc(a_size, sizeof(doublereal));
    
    x = (doublereal*)calloc(M_SIZE, sizeof(doublereal));
    y = (doublereal*)calloc(N_SIZE * 2, sizeof(doublereal)); // extra space for incy stride
    
    // Initialize input data
    for (size_t idx = 0; idx < M_SIZE; ++idx) {
        x[idx] = (doublereal)(idx % 100) * 0.1;
    }
    
    for (size_t idx = 0; idx < a_size; ++idx) {
        a[idx] = (doublereal)(idx % 200) * 0.01;
    }
    
    for (size_t idx = 0; idx < (size_t)N_SIZE * 2; ++idx) {
        y[idx] = (doublereal)(idx % 50) * 0.5;
    }
    
    // Initialize loop indices
    i__ = 0;
    j = 0;
    jy = 0;  // starting index into y vector
    temp = 0.0;
}