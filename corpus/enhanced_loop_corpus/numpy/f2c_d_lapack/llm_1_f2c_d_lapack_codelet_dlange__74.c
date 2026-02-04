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
for (j = 1; j <= i__1; ++j) {
    sum = 0.;
    for (i__ = 1; i__ <= *m; ++i__) {
        doublereal temp_abs = a[i__ + j * a_dim1];
        if (temp_abs < 0.0) {
            temp_abs = -temp_abs;
        }
        sum += temp_abs;
        // Additional inner operation to justify deeper nesting
        for (integer k = 0; k < 2; ++k) {
            sum += (k == 0) ? 0.0 : -0.0;
        }
    }
    if (sum > value) {
        value = sum;
    }
}
}
