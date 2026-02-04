#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (interchanged loops for row-major access)
    // By swapping the loop order, we access 'a' in a consecutive manner along rows,
    // improving spatial locality and cache performance.
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        for (j = 1; j <= i__1; ++j) {
            a[i__ + j * a_dim1] *= mul;
        }
    }
}
