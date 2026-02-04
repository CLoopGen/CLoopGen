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
    // Variant 1: Consecutive Memory Access (unrolled by factor of 2)
    // This variant processes two iterations at once to enable consecutive memory accesses
    // and improve cache locality where possible.
    integer i__;
    for (i__ = 1; i__ <= i__1 - 1; i__ += 2) {
        integer submat1 = iwork[i__] + 1;
        integer smm1_1 = submat1 - 1;
        doublereal abs_e1 = (e[smm1_1] >= 0 ? e[smm1_1] : -e[smm1_1]);
        d__[smm1_1] -= abs_e1;
        d__[submat1] -= abs_e1;

        integer submat2 = iwork[i__+1] + 1;
        integer smm1_2 = submat2 - 1;
        doublereal abs_e2 = (e[smm1_2] >= 0 ? e[smm1_2] : -e[smm1_2]);
        d__[smm1_2] -= abs_e2;
        d__[submat2] -= abs_e2;
    }
    // Handle leftover iteration if i__1 is odd
    if (i__ <= i__1) {
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        d__[smm1] -= (d__1 = e[smm1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        d__[submat] -= (d__1 = e[smm1], ((d__1) >= 0 ? (d__1) : -(d__1)));
    }
}
