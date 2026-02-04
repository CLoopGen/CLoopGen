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
    int idx1 = smm1;
    int idx2 = submat;
    d__[idx1] -= (r__1 = e[idx1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    d__[idx2] -= (r__1 = e[idx1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
}
}
