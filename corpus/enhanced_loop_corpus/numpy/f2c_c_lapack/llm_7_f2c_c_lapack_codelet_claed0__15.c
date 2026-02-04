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
    for (i__ = 1; i__ <= i__1; ++i__) {
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        real abs_val = e[smm1] >= 0.0f ? e[smm1] : -e[smm1];
        d__[smm1] -= abs_val;
        d__[submat] -= abs_val;
    }
}
