#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *b;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m * 2;
    for (i__ = 1; i__ <= i__2; i__ += 2) {
        b[i__ + j * b_dim1] = 0.F;
        if (i__ + 1 <= i__2) {
            b[i__ + 1 + j * b_dim1] = 1.F;
        }
    }
}
}
