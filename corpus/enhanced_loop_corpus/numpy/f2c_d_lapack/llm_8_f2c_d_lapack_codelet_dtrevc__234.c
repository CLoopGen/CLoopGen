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
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublereal temp = t[i__ + j * t_dim1];
        work[j] += temp * temp; // Replace absolute value with square to increase arithmetic intensity
    }
}
}
