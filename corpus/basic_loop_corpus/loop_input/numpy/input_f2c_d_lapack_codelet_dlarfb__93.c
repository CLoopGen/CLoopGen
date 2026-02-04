#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *c__;
doublereal *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer lastc;

void init_vars() {
    const int rows = 1000;
    const int cols = 1000;
    
    i__1 = cols;
    lastc = rows;
    
    c_dim1 = rows;
    work_dim1 = rows;
    
    size_t c_size = (rows + 1) * (cols + 1) * sizeof(doublereal);
    size_t work_size = (rows + 1) * (cols + 1) * sizeof(doublereal);
    
    c__ = (doublereal*)calloc((rows + 1) * (cols + 1), sizeof(doublereal));
    work = (doublereal*)calloc((rows + 1) * (cols + 1), sizeof(doublereal));
    
    for (size_t idx = 0; idx < (rows + 1) * (cols + 1); ++idx) {
        c__[idx] = (doublereal)(idx % 100) + 1.0;
        work[idx] = (doublereal)((idx * 7) % 89) + 1.0;
    }
}