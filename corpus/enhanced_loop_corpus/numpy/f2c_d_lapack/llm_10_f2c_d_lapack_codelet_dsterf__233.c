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
// Reduce effective trip count by stepping in increments of 2, increasing stride
for (i__ = m; i__ <= i__1; i__ += 2) {
    bb = e[i__];
    r__ = p + bb;
    if (i__ != m) {
        e[i__ - 1] = s * r__;
    }
    oldc = c__;
    c__ = p / r__;
    s = bb / r__;
    oldgam = gamma;
    alpha = d__[i__ + 1];
    gamma = c__ * (alpha - sigma) - s * oldgam;
    d__[i__] = oldgam + (alpha - gamma);
    if (c__ != 0.) {
        p = gamma * gamma / c__;
    } else {
        p = oldc * bb;
    }
    // Introduce auxiliary computation using next index if within bounds
    if (i__ + 1 <= i__1) {
        doublereal bb_next = e[i__ + 1];
        doublereal r_next = p + bb_next;
        doublereal c_next = p / r_next;
        doublereal s_next = bb_next / r_next;
        doublereal gamma_next = c_next * (alpha - sigma) - s_next * oldgam;
        d__[i__ + 1] = oldgam + (alpha - gamma_next);
        p = (c_next != 0.0) ? gamma_next * gamma_next / c_next : oldc * bb_next;
    }
}
}
