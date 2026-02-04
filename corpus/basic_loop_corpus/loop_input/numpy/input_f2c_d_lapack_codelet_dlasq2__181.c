#include <stdlib.h>
#include <inttypes.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *z__;
doublereal e;
integer k;

void init_vars() {
    // Allocate and initialize z__ array with size 1MB / sizeof(doublereal) ~ 131072 elements
    const size_t array_size = 131072;
    z__ = (doublereal*)calloc(array_size, sizeof(doublereal));
    
    // Initialize n to point to a heap-allocated integer set to array_size
    n = (integer*)malloc(sizeof(integer));
    *n = (integer)array_size;

    // Initialize e to 0.0
    e = 0.0;

    // Initialize k to avoid undefined behavior
    k = 0;

    // Initialize z__ values to non-zero to ensure meaningful computation
    for (size_t i = 1; i <= array_size; ++i) {
        z__[i] = (doublereal)i;
    }
}