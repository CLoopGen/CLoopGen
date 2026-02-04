#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef float real;
typedef int integer;

real *d__;
integer i__1;
integer i__2;
integer i__;
integer j;
real dmnmx;
integer start;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M elements, ~4MB for floats
    d__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    
    if (!d__) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        d__[idx] = (real)(data_size - idx);
    }

    start = 1;
    i__1 = data_size - 1;
    i__2 = start + 1;
    i__ = 0;
    j = 0;
    dmnmx = 0.0f;
}