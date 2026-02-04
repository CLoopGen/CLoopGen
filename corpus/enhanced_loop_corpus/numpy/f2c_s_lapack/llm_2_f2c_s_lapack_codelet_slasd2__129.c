#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *beta;
extern real *vt;
extern integer vt_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements in vt, use a stride of 2
    // This changes the memory access pattern to every second element
    integer stride = 2;
    for (i__ = nlp2; i__ <= i__1; i__ += stride) {
        z__[i__] = *beta * vt[i__ + nlp2 * vt_dim1];
    }
    // Handle remaining element if range size is odd
    if ((i__1 - nlp2 + 1) % 2 == 1 && i__1 >= nlp2) {
        z__[i__1] = *beta * vt[i__1 + nlp2 * vt_dim1];
    }
}
