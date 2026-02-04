#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real prev_val = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        real current = *beta + prev_val;
        a[i__ + i__ * a_dim1] = current;
        prev_val = current;
    }
}
