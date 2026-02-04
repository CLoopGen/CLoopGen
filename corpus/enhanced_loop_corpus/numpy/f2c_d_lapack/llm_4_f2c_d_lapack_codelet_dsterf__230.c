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
for (i__ = m - 1; i__ >= i__1; --i__) {
    bb = e[i__];
    r__ = p + bb;
    if (i__ != m - 1) {
        e[i__ + 1] = s * r__;
    }
    oldc = c__;
    c__ = p / r__;
    s = bb / r__;
    oldgam = gamma;
    alpha = d__[i__];
    gamma = c__ * (alpha - sigma) - s * oldgam;
    d__[i__ + 1] = oldgam + (alpha - gamma);
    p = (c__ != 0.0) ? (gamma * gamma / c__) : (oldc * bb);
}
}
