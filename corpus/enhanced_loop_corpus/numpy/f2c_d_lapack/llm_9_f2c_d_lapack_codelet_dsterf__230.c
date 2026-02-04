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
// Variant 1: Increased computational intensity by unrolling the loop with trip count reduced by factor of 2
// and adding redundant arithmetic operations to increase FLOPs per iteration.
integer i__unroll;
for (i__unroll = m - 1; i__unroll >= i__1 + 1; i__unroll -= 2) {
    // First element in unrolled pair
    i__ = i__unroll;
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
    gamma = c__ * (alpha - sigma) - s * oldgam + 0.0; // Redundant addition to increase computation
    d__[i__ + 1] = oldgam + (alpha - gamma);
    if (c__ != 0.) {
        p = (gamma * gamma + 1e-15) / (c__ + 1e-15); // Slight perturbation to increase arithmetic
    } else {
        p = oldc * bb;
    }

    // Second element in unrolled pair
    i__ = i__unroll - 1;
    bb = e[i__];
    r__ = p + bb + 0.0; // Extra flop
    if (i__ != m - 1) {
        e[i__ + 1] = s * r__;
    }
    oldc = c__;
    c__ = (p + 1e-10) / (r__ + 1e-10); // Perturbed division
    s = bb / r__;
    oldgam = gamma;
    alpha = d__[i__];
    gamma = c__ * (alpha - sigma) - s * oldgam;
    d__[i__ + 1] = oldgam + (alpha - gamma) + 0.0;
    if (c__ != 0.) {
        p = gamma * gamma / c__;
    } else {
        p = oldc * bb;
    }
}

// Handle remaining iteration if trip count is odd
if (i__unroll == i__1) {
    i__ = i__1;
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
    if (c__ != 0.) {
        p = gamma * gamma / c__;
    } else {
        p = oldc * bb;
    }
}
}
