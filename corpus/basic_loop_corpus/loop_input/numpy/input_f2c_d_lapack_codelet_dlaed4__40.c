#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
doublereal *delta;
integer i__1;
integer j;
doublereal psi;
doublereal dpsi;
doublereal temp;
doublereal erretm;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime on modern CPU
    // For typical performance, use array size around 1M to 2M elements
    i__1 = 2000000;  // 2 million elements -> ~32 MB per array
    
    // Allocate arrays with proper bounds
    z__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    delta = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    
    // Initialize arrays to avoid division by zero and ensure predictable computation
    for (integer i = 1; i <= i__1; ++i) {
        z__[i] = 1.0 + 0.01 * (i % 17);
        delta[i] = 0.5 + 0.02 * (i % 13);
    }
    
    // Initialize scalar variables
    psi = 0.0;
    dpsi = 0.0;
    temp = 0.0;
    erretm = 0.0;
    j = 0; // Will be incremented in loop
}