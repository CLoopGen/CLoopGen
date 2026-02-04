#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer *iwork;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern integer smm1;
extern integer submat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1; i__ += 2) {
    integer j1 = iwork[i__ - 1] + 1;
    integer j2 = iwork[i__] + 1;
    integer s1 = j1 - 1;
    integer s2 = j2 - 1;
    d__[s1] -= (d__1 = e[s1], ((d__1) >= 0 ? (d__1) : -(d__1)));
    d__[j1] -= (d__1 = e[s1], ((d__1) >= 0 ? (d__1) : -(d__1)));
    d__[s2] -= (d__1 = e[s2], ((d__1) >= 0 ? (d__1) : -(d__1)));
    d__[j2] -= (d__1 = e[s2], ((d__1) >= 0 ? (d__1) : -(d__1)));
}
}
