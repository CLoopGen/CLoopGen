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
doublereal prev_gamma = gamma;
doublereal prev_c = c__;
for (i__ = m; i__ <= i__1; ++i__) {
    bb = e[i__];
    r__ = p + bb;
    if (i__ != m) {
        e[i__ - 1] = s * r__;
    }
    c__ = p / r__;
    s = bb / r__;
    alpha = d__[i__ + 1];
    gamma = c__ * (alpha - sigma) - s * prev_gamma;
    d__[i__] = prev_gamma + (alpha - gamma);
    if (c__ != 0.) {
        p = gamma * gamma / c__;
    } else {
        p = prev_c * bb;
    }
    prev_gamma = gamma;
    prev_c = c__;
}
}
