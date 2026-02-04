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
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;
extern integer k3;
extern integer k4;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= k3; ++i__) {
    for (j = 1; j <= i__1 && j <= k4 - i__; ++j) {
        a[i__ + j * a_dim1] *= mul;
    }
}
}
