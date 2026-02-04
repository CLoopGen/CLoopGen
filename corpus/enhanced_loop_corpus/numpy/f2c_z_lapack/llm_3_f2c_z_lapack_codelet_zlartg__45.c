#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *r__;
extern integer i__1;
extern doublecomplex z__1;
extern integer i__;
extern doublereal safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2 (process every second element)
    doublecomplex *r_array = r__;
    integer stride = 2;
    integer limit = (i__1 + stride - 1) / stride; // Adjust count for strided traversal
    for (i__ = 0; i__ < limit; ++i__) {
        integer idx = i__ * stride;
        z__1.r = safmx2 * r_array[idx].r;
        z__1.i = safmx2 * r_array[idx].i;
        r_array[idx].r = z__1.r;
        r_array[idx].i = z__1.i;
    }
}
