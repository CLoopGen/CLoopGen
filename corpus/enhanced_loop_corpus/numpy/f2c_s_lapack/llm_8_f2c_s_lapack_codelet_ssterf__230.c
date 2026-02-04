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
    if (c__ != 0.F) {
        p = gamma * gamma / c__;
    } else {
        p = oldc * bb;
    }
    // Additional arithmetic to increase computational intensity
    p = (p > 0.F) ? p + 0.5F * c__ * s : p - 0.25F * oldc;
    gamma = gamma + 0.1F * (r__ + bb) / (p + 1e-9F);
}
}
