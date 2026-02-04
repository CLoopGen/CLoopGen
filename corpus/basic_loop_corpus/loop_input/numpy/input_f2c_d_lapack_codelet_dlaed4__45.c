#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *z__;
doublereal *delta;
integer i__1;
integer j;
doublereal phi;

static doublereal *z_buffer;
static doublereal *delta_buffer;
static integer n_value;

void init_vars() {
    // Aim for approximately 100 million iterations to target ~0.01 sec runtime
    n_value = 100000000;
    i__1 = 1;
    phi = 0.0;
    
    // Allocate arrays with extra space to avoid out-of-bounds access
    z_buffer = (doublereal*)calloc(n_value + 1, sizeof(doublereal));
    delta_buffer = (doublereal*)calloc(n_value + 1, sizeof(doublereal));
    
    // Initialize arrays with non-zero values to avoid division by zero
    for (integer i = 1; i <= n_value; ++i) {
        z_buffer[i] = sin(i * 0.01);
        delta_buffer[i] = fabs(cos(i * 0.01)) + 1.0; // Ensure positive and non-zero
    }
    
    // Assign pointers
    n = &n_value;
    z__ = z_buffer;
    delta = delta_buffer;
}