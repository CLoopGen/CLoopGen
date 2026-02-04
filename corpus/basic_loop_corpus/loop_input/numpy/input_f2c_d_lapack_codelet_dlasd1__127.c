#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer i__1;
doublereal d__1;
integer i__;
doublereal orgnrm;

void init_vars() {
    // Allocate approximately 16 million elements to ensure loop takes ~0.01 seconds
    // assuming each iteration is a few cycles and modern CPU at ~3GHz
    size_t data_size = 16000000;
    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    
    if (!d__) {
        exit(1);
    }
    
    // Initialize array with random-like values centered around zero
    for (size_t j = 0; j < data_size; ++j) {
        d__[j] = (double)(rand() - RAND_MAX/2) / RAND_MAX * 1000.0;
    }
    
    // Set loop bounds: use full allocated size
    i__1 = (integer)data_size;
    
    // Initialize orgnrm to zero so that first absolute value will exceed it
    orgnrm = 0.0;
    
    // Initialize loop index
    i__ = 1;
}