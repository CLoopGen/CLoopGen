#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern doublereal *work;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;
extern doublereal sum;
extern doublereal absa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    sum = 0.;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        absa = (d__1 = a[i__ + (j * a_dim1)] , ((d__1) >= 0 ? (d__1) : -(d__1)));
        sum += absa;
        work[i__] += absa;
    }
    work[j] = sum + (d__1 = a[j + (j * a_dim1)] , ((d__1) >= 0 ? (d__1) : -(d__1)));
}
}
