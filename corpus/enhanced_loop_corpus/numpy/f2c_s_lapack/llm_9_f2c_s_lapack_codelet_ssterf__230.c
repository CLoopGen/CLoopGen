#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *e;
extern integer i__1;
extern real c__;
extern integer i__;
extern integer m;
extern real p;
extern real r__;
extern real s;
extern real bb;
extern real oldc;
extern real gamma;
extern real alpha;
extern real sigma;
extern real oldgam;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count by stepping more than one index per iteration
integer step = 2;
for (i__ = m - 1; i__ >= i__1 + step - 1; i__ -= step) {
    // Process two iterations in one, unrolled manually
    // First element (i__)
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
    if (c__ != 0.F) {
        p = gamma * gamma / c__;
    } else {
        p = oldc * bb;
    }

    // Second element (i__ - 1), with bounds check logic preserved via conditional
    if (i__ - 1 >= i__1) {
        bb = e[i__ - 1];
        r__ = p + bb;
        e[i__] = s * r__;  // since (i__ - 1 + 1) = i__
        oldc = c__;
        c__ = p / r__;
        s = bb / r__;
        oldgam = gamma;
        alpha = d__[i__ - 1];
        gamma = c__ * (alpha - sigma) - s * oldgam;
        d__[i__] = oldgam + (alpha - gamma);  // d__[i__ - 1 + 1]
        if (c__ != 0.F) {
            p = gamma * gamma / c__;
        } else {
            p = oldc * bb;
        }
    }
}
}
