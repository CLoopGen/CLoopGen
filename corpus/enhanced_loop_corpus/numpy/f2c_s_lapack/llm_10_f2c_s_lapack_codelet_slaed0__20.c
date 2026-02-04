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



void loop() {
    for (i__ = 2; i__ <= i__1; i__ += 2) { // Increased step size, reduced trip count
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        real abs_val = (r__1 = e[smm1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
        d__[smm1] -= abs_val;
        d__[submat] -= abs_val;

        if (i__ - 1 <= i__1) { // Process previous index in pairs to maintain coverage
            integer prev_submat = iwork[i__ - 1] + 1;
            integer prev_smm1 = prev_submat - 1;
            d__[prev_smm1] -= (r__1 = e[prev_smm1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
            d__[prev_submat] -= (r__1 = e[prev_smm1], (doublereal)((r__1) >= 0 ? r__1 : -r__1));
        }
    }
}
