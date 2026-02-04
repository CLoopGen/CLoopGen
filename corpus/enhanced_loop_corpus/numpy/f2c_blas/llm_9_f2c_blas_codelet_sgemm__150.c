#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m * 2;
    for (i__ = 1; i__ <= i__2; i__ += 2) {
        if (i__ <= *m) {
            c__[i__ + j * c_dim1] = 0.F;
        }
        if (i__ + 1 <= *m) {
            c__[i__ + 1 + j * c_dim1] = 0.F;
        }
    }
}
}
