#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = kk + 1; j <= i__1; j += 2) {
    i__2 = kk >> 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        a[(i__ << 1) + j * a_dim1] = 0.F;
    }
}
}
