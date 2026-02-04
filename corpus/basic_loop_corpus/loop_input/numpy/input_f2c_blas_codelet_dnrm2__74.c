#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *x;
integer i__1;
integer i__2;
doublereal d__1;
integer ix;
doublereal ssq;
doublereal scale;
doublereal absxi;

void init_vars() {
    // Allocate approximately 64MB of data to ensure loop takes ~0.01s
    const size_t data_size = 8 * 1024 * 1024; // 8M doubles = ~64 MB
    x = (doublereal*)calloc(data_size, sizeof(doublereal));
    
    if (!x) {
        exit(1);
    }
    
    // Initialize array with non-zero values in a pattern that triggers both branches
    for (size_t i = 0; i < data_size; i++) {
        x[i] = sin(i * 0.01) * 100.0;
    }
    
    // Set loop bounds to iterate over entire allocated array
    i__1 = (integer)(data_size - 1);
    i__2 = 1;  // positive increment
    
    // Initialize reduction variables
    scale = 1.0;
    ssq = 0.0;
    d__1 = 0.0;
    ix = 1;  // will be set by loop, but initialize anyway
    absxi = 0.0;
}