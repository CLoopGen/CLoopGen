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
for (j = 1; j <= i__1 && j <= 100; ++j) { // Bound trip count to reduce complexity
    i__2 = (j % 2 == 0) ? j : j - 1; // Modify inner loop bounds based on parity
    if (i__2 <= 0) continue;
    for (i__ = 1; i__ <= i__2; i__ += 2) { // Stride-2 iteration to reduce operations
        d__2 = value;
        d__3 = (d__1 = a[i__ + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        value = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
}
}
