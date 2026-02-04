#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *c__;
real *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer lastc;

void init_vars() {
    i__1 = 500;      
    lastc = 500;     
    c_dim1 = 500;    
    work_dim1 = 500; 

    size_t c_size = (lastc + 1) * (i__1 + 1);
    size_t work_size = (lastc + 1) * (i__1 + 1);

    c__ = (real*)calloc(c_size, sizeof(real));
    work = (real*)calloc(work_size, sizeof(real));

    if (c__ == NULL || work == NULL) {
        exit(1);
    }

    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx] = (real)(idx % 100) + 1.0f;
    }
    for (size_t idx = 0; idx < work_size; ++idx) {
        work[idx] = (real)(idx % 50) + 0.5f;
    }
}