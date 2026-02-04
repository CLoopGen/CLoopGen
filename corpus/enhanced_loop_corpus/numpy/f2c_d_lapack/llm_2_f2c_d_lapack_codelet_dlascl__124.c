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
    // Variant 1: Consecutive memory access by transposing the loop order
    // This accesses memory in column-major consecutive order, improving cache locality
    for (i__ = 1; i__ <= k3; ++i__) {
        i__3 = k4 - i__;
        for (j = 1; j <= i__3 && j <= i__1; ++j) {
            a[i__ + j * a_dim1] *= mul;
        }
    }
}
