#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *t;
extern doublereal *work;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    work[j] = 0.;
    for (int k = 1; k <= j - 1; ++k) {
        i__ = k;
        work[j] += (d__1 = t[i__ + j * t_dim1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
    }
}
}
