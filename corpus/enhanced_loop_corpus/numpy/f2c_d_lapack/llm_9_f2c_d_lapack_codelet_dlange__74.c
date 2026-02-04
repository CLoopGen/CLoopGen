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
for (j = 1; j <= i__1; j += 2) {
    sum = 0.;
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublereal val1 = a[i__ + j * a_dim1];
        doublereal abs_val1 = val1 >= 0.0 ? val1 : -val1;
        sum += abs_val1;
        if (j + 1 <= i__1) {
            doublereal val2 = a[i__ + (j + 1) * a_dim1];
            doublereal abs_val2 = val2 >= 0.0 ? val2 : -val2;
            sum += abs_val2;
        }
    }
    value = value >= sum ? value : sum;
}
}
