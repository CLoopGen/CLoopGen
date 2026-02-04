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
extern integer i__;
extern integer j;
extern integer k1;
extern integer k3;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= k3; ++i__) {
    for (j = 1; j <= i__1; ++j) {
        i__2 = k1 - j;
        if (i__ >= ((i__2) >= (1) ? (i__2) : (1))) {
            a[i__ + j * a_dim1] *= mul; // Interchanged loop order for consecutive column access
        }
    }
}
}
