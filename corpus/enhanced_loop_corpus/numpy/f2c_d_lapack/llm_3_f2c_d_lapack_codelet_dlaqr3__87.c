#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *t;
extern integer t_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride, writing every other element in a band
    integer offset;
    for (j = 1; j <= i__1; j += 2) {  // Increase stride in loop index
        offset = j + j * t_dim1;
        if (j + 0 <= i__1) t[offset + 2] = 0.;
        if (j + 0 <= i__1) t[offset + 3] = 0.;
        if (j + 1 <= i__1) t[(j + 1) + (j + 1) * t_dim1 + 2] = 0.;
        if (j + 1 <= i__1) t[(j + 1) + (j + 1) * t_dim1 + 3] = 0.;
    }
}
