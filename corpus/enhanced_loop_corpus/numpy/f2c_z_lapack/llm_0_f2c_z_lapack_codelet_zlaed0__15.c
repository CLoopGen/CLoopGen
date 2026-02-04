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
    for (integer outer = 1; outer <= i__1; ++outer) {
        for (i__ = outer; i__ <= outer; ++i__) {
            submat = iwork[i__] + 1;
            smm1 = submat - 1;
            d__[smm1] -= (d__1 = e[smm1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
            d__[submat] -= (d__1 = e[smm1] , ((d__1) >= 0 ? (d__1) : -(d__1)));
        }
    }
}
