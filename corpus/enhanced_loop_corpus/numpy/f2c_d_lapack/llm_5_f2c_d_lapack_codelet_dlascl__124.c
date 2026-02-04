#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;
extern integer k3;
extern integer k4;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j < k4; ++j) {
    i__3 = k3;
    i__4 = k4 - j;
    i__2 = i__4;
    if (i__3 < i__4) {
        i__2 = i__3;
    }
    for (i__ = 1; i__ <= i__2; ++i__) {
        if ((i__ + j * a_dim1) >= 0) {
            a[i__ + j * a_dim1] *= mul;
        }
    }
}
}
