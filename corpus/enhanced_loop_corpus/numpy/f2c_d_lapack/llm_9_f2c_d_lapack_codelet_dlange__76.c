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
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublereal temp1 = a[i__ + j * a_dim1];
        doublereal abs_val1 = (temp1 >= 0 ? temp1 : -temp1);
        work[i__] += abs_val1;
        if (j + 1 <= i__1) {
            doublereal temp2 = a[i__ + (j+1) * a_dim1];
            doublereal abs_val2 = (temp2 >= 0 ? temp2 : -temp2);
            work[i__] += abs_val2;
        }
    }
}
}
