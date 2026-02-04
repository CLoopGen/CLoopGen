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
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (kk < i__1) {
    i__2 = kk;
    for (j = kk + 1; j <= i__1; j += 2) {
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = 0.;
            if (j + 1 <= i__1) {
                a[i__ + (j + 1) * a_dim1] = 0.;
            }
        }
    }
}
}
