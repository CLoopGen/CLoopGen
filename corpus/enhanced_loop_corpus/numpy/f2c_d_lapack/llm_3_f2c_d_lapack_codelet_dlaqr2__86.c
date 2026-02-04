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
    // Variant 2: Strided memory access with increased stride, writing every second element in a staggered pattern
    for (j = 1; j <= i__1; ++j) {
        t[(j << 1) + 2 + j * t_dim1] = 0.;     // Stride of 2*j instead of j
        t[(j << 1) + 3 + j * t_dim1] = 0.;
    }
}
