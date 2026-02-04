#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;
extern doublereal sum;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_value = value;
    for (j = 1; j <= i__1; ++j) {
        doublereal sum_j = 0.;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            sum_j += (d__1 = a[i__ + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        }
        if (sum_j > local_value) {
            local_value = sum_j;
        }
    }
    value = local_value;
}
