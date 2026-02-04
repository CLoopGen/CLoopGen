#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *da;
doublereal *dx;
doublereal *dy;
integer i__1;
integer i__;

#define DATA_SIZE (1 << 20) // 1 million elements, ~8MB per array

doublereal da_val;
doublereal *dx_arr;
doublereal *dy_arr;

void init_vars() {
    // Allocate memory for arrays
    dx_arr = (doublereal*)aligned_alloc(32, DATA_SIZE * sizeof(doublereal));
    dy_arr = (doublereal*)aligned_alloc(32, DATA_SIZE * sizeof(doublereal));
    
    // Initialize scalar
    da_val = 1.5;
    
    // Initialize arrays to avoid NaN or infinity that could slow down computation
    for (int i = 0; i < DATA_SIZE; ++i) {
        dx_arr[i] = (doublereal)(i % 100) / 10.0;
        dy_arr[i] = (doublereal)(i % 50) / 20.0;
    }
    
    // Set external pointers and bounds
    da = &da_val;
    dx = dx_arr;
    dy = dy_arr;
    i__1 = DATA_SIZE - 1;  // loop goes from 1 to i__1 inclusive
}