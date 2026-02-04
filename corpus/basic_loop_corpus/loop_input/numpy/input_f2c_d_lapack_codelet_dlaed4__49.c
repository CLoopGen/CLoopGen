#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
doublereal *delta = NULL;
integer i__1 = 0;
integer j = 0;
doublereal psi = 0.0;
doublereal dpsi = 0.0;
doublereal temp = 0.0;
doublereal erretm = 0.0;

void init_vars() {
    const size_t data_size_bytes = 64 * 1024 * 1024; 
    const size_t num_elements = data_size_bytes / sizeof(doublereal);
    
    z__ = (doublereal*)aligned_alloc(32, num_elements * sizeof(doublereal));
    delta = (doublereal*)aligned_alloc(32, num_elements * sizeof(doublereal));

    for (size_t i = 0; i < num_elements; ++i) {
        z__[i] = sin(i + 1.0) * 0.5;
        delta[i] = fabs(sin(i * 0.1)) + 1e-10;
    }

    i__1 = (integer)(num_elements - 1);

    psi = 1e-8;
    dpsi = 1e-8;
    erretm = 0.0;
    j = 0;
}