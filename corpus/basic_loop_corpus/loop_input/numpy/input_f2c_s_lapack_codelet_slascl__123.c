#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
real mul;

#define A_SIZE 8192

void init_vars() {
    const integer size_m = 4096;
    a_dim1 = size_m;
    i__1 = size_m - 1;
    mul = 1.5f;
    
    m = &size_m;
    
    size_t total_elements = (size_m + 1) * (size_m + 1);
    a = (real*)aligned_alloc(32, total_elements * sizeof(real));
    
    if (!a) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx] = (real)(idx % 100) / 10.0f;
    }
}