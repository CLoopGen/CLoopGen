#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef double doublereal;

integer *m;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
integer i__;
integer j;
real sum;
real value;

void init_vars() {
    // Set matrix dimensions
    const integer rows = 5000;
    const integer cols = 5000;
    
    // Allocate memory for matrix a with leading dimension a_dim1 >= rows
    a_dim1 = rows;
    size_t total_elements = (size_t)a_dim1 * (size_t)cols;
    a = (real*)calloc(total_elements, sizeof(real));
    if (!a) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize matrix with sample data to avoid all zeros
    for (integer idx = 0; idx < total_elements; ++idx) {
        a[idx] = (real)(sin(idx % 100) * 100.0f);
    }
    
    // Set loop bounds
    *m = rows;
    i__1 = cols;
    
    // Initialize other variables
    i__2 = 0;
    r__1 = 0.0f;
    i__ = 0;
    j = 0;
    sum = 0.0f;
    value = 0.0f;
}

// Allocate and initialize m after its declaration
static integer m_storage = 0;
integer *m = &m_storage;