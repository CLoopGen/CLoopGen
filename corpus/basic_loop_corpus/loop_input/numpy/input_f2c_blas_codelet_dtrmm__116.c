#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
integer *n;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

void init_vars() {
    // Set problem size for ~0.01 sec runtime on modern CPU
    // Based on typical performance, use m = n = 512 to 1024
    int size = 768;  // Balanced for cache and computation
    
    // Allocate and initialize m and n
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    *m = size;
    *n = size;
    
    // Allocate and initialize alpha
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;
    
    // Set matrix leading dimensions
    a_dim1 = *m;
    b_dim1 = *m;
    
    // Allocate matrices a and b: column-major, size x size
    int a_size = a_dim1 * (*n);
    int b_size = b_dim1 * (*n);
    
    a = (doublereal*)aligned_alloc(64, a_size * sizeof(doublereal));
    b = (doublereal*)aligned_alloc(64, b_size * sizeof(doublereal));
    
    // Initialize a and b with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < a_size; ++idx) {
        a[idx] = sin(idx * 0.01);
    }
    for (int idx = 0; idx < b_size; ++idx) {
        b[idx] = cos(idx * 0.01);
    }
    
    // Ensure diagonal of a is non-zero even if nounit is false
    for (int i = 0; i < *n; ++i) {
        a[i + i * a_dim1] = 2.0;
    }
    
    // Set nounit: true means unit diagonal is not assumed
    nounit = 1;
    
    // Initialize loop indices and temps to safe values
    i__1 = 0;
    i__2 = 0;
    i__ = 0;
    j = 0;
    k = 0;
    temp = 0.0;
}