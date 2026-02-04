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
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern integer j;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = j;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer idx = (i__ - 1) * a_dim1 + j; // Transposed access pattern: column-major traversal
        d__2 = value , d__3 = (d__1 = a[idx] , ((d__1) >= 0 ? (d__1) : -(d__1)));
        value = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
}
}
