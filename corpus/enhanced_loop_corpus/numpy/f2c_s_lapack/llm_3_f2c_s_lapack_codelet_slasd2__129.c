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
    // Variant 2: Consecutive Reverse Memory Access Pattern
    // Traverse the array in reverse order to improve cache locality in certain access scenarios
    // and ensure consecutive backward memory access
    for (i__ = i__1; i__ >= nlp2; --i__) {
        z__[i__] = *beta * vt[i__ + nlp2 * vt_dim1];
    }
}
