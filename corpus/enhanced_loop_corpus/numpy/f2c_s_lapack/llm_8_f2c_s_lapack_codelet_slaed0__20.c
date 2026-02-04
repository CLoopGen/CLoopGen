#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern real *e;
extern integer *iwork;
extern integer i__1;
extern real r__1;
extern integer i__;
extern integer smm1;
extern integer submat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_sum = 0.0f;
    for (i__ = 1; i__ <= i__1; ++i__) {
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        real abs_val = (e[smm1] >= 0.0f) ? e[smm1] : -e[smm1];
        temp_sum += abs_val;  // Introduce accumulation (WAW dependency on temp_sum, no loop-carried dep on d__)
    }
    // Remove loop-carried dependencies and collapse updates into a single post-loop operation
    for (i__ = 1; i__ <= i__1; ++i__) {
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        d__[smm1] -= temp_sum;
        d__[submat] -= temp_sum;
    }
}
