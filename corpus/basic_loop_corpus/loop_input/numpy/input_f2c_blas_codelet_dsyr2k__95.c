#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__ = 0;
integer j = 0;

void init_vars() {
    // Estimate problem size to run loop for ~0.01 seconds
    // The loop runs j from 1 to i__1, and for each j, i__ from 1 to j
    // Total iterations ≈ i__1*(i__1+1)/2 ≈ 10^7 for 0.01 sec on modern CPU
    
    i__1 = 4500;  // Gives ~10 million iterations
    c_dim1 = i__1 + 100;  // Slightly larger leading dimension for safety
    
    // Allocate memory with appropriate size (at least i__1*c_dim1 elements)
    size_t alloc_size = (size_t)(i__1 + 1) * (c_dim1 + 1);
    c__ = (doublereal*)calloc(alloc_size, sizeof(doublereal));
    
    // Initialize loop counters to safe values
    i__ = 0;
    j = 0;
    i__2 = 0;
}