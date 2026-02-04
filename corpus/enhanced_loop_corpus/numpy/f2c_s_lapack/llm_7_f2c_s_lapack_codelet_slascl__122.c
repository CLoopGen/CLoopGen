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
    for (j = 1; j <= i__1; ++j) {
        i__2 = ((j) <= (*m) ? (j) : (*m));
        real prev_val = 1.0f;
        for (i__ = 1; i__ <= i__2; ++i__) {
            real current = a[i__ + j * a_dim1];
            a[i__ + j * a_dim1] = current * mul + prev_val; // Introduce loop-carried RAW dependency
            prev_val = current; // Carry value from previous iteration
        }
    }
}
