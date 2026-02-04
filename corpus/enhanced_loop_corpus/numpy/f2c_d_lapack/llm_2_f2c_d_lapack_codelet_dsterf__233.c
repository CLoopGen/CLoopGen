#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer i__1;
extern doublereal c__;
extern integer i__;
extern integer m;
extern doublereal p;
extern doublereal r__;
extern doublereal s;
extern doublereal bb;
extern doublereal oldc;
extern doublereal gamma;
extern doublereal alpha;
extern doublereal sigma;
extern doublereal oldgam;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = m; i__ <= i__1; ++i__) {
    ptrdiff_t idx = i__; // Consecutive forward access with explicit indexing
    bb = e[idx];
    r__ = p + bb;
    if (idx != m) {
        e[idx - 1] = s * r__;
    }
    oldc = c__;
    c__ = p / r__;
    s = bb / r__;
    oldgam = gamma;
    alpha = d__[idx + 1];
    gamma = c__ * (alpha - sigma) - s * oldgam;
    d__[idx] = oldgam + (alpha - gamma);
    if (c__ != 0.) {
        p = gamma * gamma / c__;
    } else {
        p = oldc * bb;
    }
}
}
