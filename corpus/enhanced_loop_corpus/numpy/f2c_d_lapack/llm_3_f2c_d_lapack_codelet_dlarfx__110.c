#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;
extern doublereal t2;
extern doublereal t3;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride pattern (simulating access to a transposed layout)
    // Here, we simulate a column-major strided access by increasing the step in j to skip elements
    // This variant assumes that effective work is done on every 4th element, mimicking sparse or blocked data layout
    const integer stride = 4;
    integer limit = i__1 / stride;

    for (j = 1; j <= limit; ++j) {
        integer base = j * stride;
        integer idx1 = base + c_dim1;
        integer idx2 = base + (c_dim1 << 1);
        integer idx3 = base + c_dim1 * 3;
        
        sum = v1 * c__[idx1] + v2 * c__[idx2] + v3 * c__[idx3];
        c__[idx1] -= sum * t1;
        c__[idx2] -= sum * t2;
        c__[idx3] -= sum * t3;
    }
}
