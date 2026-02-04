#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern doublereal *work;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i__2 = *m;
    for (j = 1; j <= i__1; ++j) {
        for (i__ = 1; i__ <= i__2; ++i__) {
            for (integer k = 0; k < 1; ++k) {
                work[i__] += (d__1 = a[i__ + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
            }
        }
    }
}
