#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern doublereal d__4;
extern doublereal d__5;
extern integer i__;
extern doublereal anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal temp_sum = 0.0;
        doublereal val;

        val = d__[i__];
        temp_sum += val >= 0.0 ? val : -val;

        val = e[i__];
        temp_sum += val >= 0.0 ? val : -val;

        val = e[i__ - 1];
        temp_sum += val >= 0.0 ? val : -val;

        if (temp_sum < anorm) {
            continue;
        } else {
            anorm = temp_sum;
        }
    }
}
