#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base pointer offset
    real sa_val = *sa;
    real *sx_local = sx + mp1;
    real *sy_local = sy + mp1;
    integer count = (i__1 - mp1 + 1) / 4;
    for (i__ = 0; i__ < count; ++i__) {
        sy_local[0] += sa_val * sx_local[0];
        sy_local[1] += sa_val * sx_local[1];
        sy_local[2] += sa_val * sx_local[2];
        sy_local[3] += sa_val * sx_local[3];
        sx_local += 4;
        sy_local += 4;
    }
}
