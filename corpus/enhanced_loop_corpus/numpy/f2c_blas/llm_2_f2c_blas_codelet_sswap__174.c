#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;
extern integer mp1;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    real *sx_ptr = sx + mp1;
    real *sy_ptr = sy + mp1;
    integer remaining = (i__1 - mp1 + 1);
    for (i__ = 0; i__ < remaining; i__ += 3) {
        stemp = sx_ptr[i__];
        sx_ptr[i__] = sy_ptr[i__];
        sy_ptr[i__] = stemp;
        stemp = sx_ptr[i__ + 1];
        sx_ptr[i__ + 1] = sy_ptr[i__ + 1];
        sy_ptr[i__ + 1] = stemp;
        stemp = sx_ptr[i__ + 2];
        sx_ptr[i__ + 2] = sy_ptr[i__ + 2];
        sy_ptr[i__ + 2] = stemp;
    }
}
