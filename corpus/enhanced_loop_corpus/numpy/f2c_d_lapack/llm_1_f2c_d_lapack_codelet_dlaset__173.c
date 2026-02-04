#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (integer k = j; k <= i__2; ++k) {
        for (i__ = k; i__ <= k; ++i__) {
            if (i__ > j) {
                a[i__ + j * a_dim1] = *alpha;
            }
        }
    }
}
}
