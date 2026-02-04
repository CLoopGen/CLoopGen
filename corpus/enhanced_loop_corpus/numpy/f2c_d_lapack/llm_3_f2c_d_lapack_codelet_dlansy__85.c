#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
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
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    sum = 0.0;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublereal temp_val1 = (d__1 = a[i__ + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        sum += temp_val1;
        work[i__] += temp_val1;
        if (j + 1 <= i__1 && i__ != j + 1) {
            doublereal temp_val2 = (d__1 = a[i__ + (j+1) * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
            sum += temp_val2;
            work[i__] += temp_val2;
        }
    }
    value = ((value) >= (sum) ? (value) : (sum));
}
}
