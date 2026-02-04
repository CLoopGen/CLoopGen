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

integer *ihi;
doublecomplex *tau;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    // Allocate a large enough array to make the loop take ~0.01 seconds
    // Assuming modern CPU can do ~1e9 operations/sec, 0.01 sec = 1e7 operations
    // We'll use around 8 million elements for measurable duration
    const size_t array_size = 8000000;
    
    // Allocate tau array
    tau = (doublecomplex*)calloc(array_size, sizeof(doublecomplex));
    
    // Initialize ihi to point near the end of valid range to ensure loop runs
    ihi = (integer*)malloc(sizeof(integer));
    *ihi = array_size - 100000;  // Start close to beginning of array
    
    // Set i__1 to be the upper bound within array bounds
    i__1 = array_size - 1;
    
    // Initialize work variables
    i__2 = 0;
    i__ = 0;
}