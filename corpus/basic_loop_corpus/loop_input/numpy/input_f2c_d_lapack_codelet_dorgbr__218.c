#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;

static doublereal *a_data = NULL;

void init_vars() {
    a_dim1 = 4096;
    i__1 = 4096;
    
    size_t total_size = (size_t)(a_dim1 + 1) * (size_t)(i__1 + 1);
    a_data = (doublereal*)calloc(total_size, sizeof(doublereal));
    
    if (!a_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    a = a_data - 1 - a_dim1;
    
    for (int idx = 0; idx < total_size; ++idx) {
        a_data[idx] = (doublereal)(idx % 1000) / 100.0;
    }
}