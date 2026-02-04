#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
integer i__;
integer j;
integer k1;
integer k2;
integer k3;
integer k4;
real mul;

void init_vars() {
    const size_t target_size = 64 * 1024 * 1024; // ~64MB for reasonable timing (~0.01s)
    const size_t element_size = sizeof(singlecomplex);
    const size_t total_elements = target_size / element_size;
    
    // Choose square-ish dimensions
    a_dim1 = (integer)(total_elements / 10); // Use roughly 1/10th as row size
    if (a_dim1 < 100) a_dim1 = 100;
    
    size_t num_elements = a_dim1 * 12; // Ensure enough columns
    singlecomplex *temp_a = malloc(num_elements * sizeof(singlecomplex));
    if (!temp_a) {
        exit(1);
    }
    a = temp_a;
    
    // Initialize array data
    for (size_t idx = 0; idx < num_elements; ++idx) {
        a[idx].r = (real)(idx % 17 + 1);
        a[idx].i = (real)(idx % 19 + 1);
    }
    
    // Set loop bounds to valid range within allocated memory
    i__1 = 10;           // outer loop: j from 1 to 10
    k1 = a_dim1 - 5;     // ensure k1-j >= 0
    k2 = 1;              // lower bound for i__
    k3 = a_dim1 - 1;     // upper bound from k3
    k4 = a_dim1 + 5;     // another upper bound, will be capped by k3
    mul = 1.5f;          // arbitrary scaling factor
    
    // Ensure inner loop stays in bounds
    // i__ runs from max(k1-j, k2) to min(k3, k4-j), and we access i__+j*a_dim1
    // So maximum index is about (k3) + (i__1)*a_dim1 <= (a_dim1-1) + 10*a_dim1 = 11*a_dim1 -1
    // We allocated 12*a_dim1, so safe.
}