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
integer stride = 2;
integer start = (m % stride == 0) ? m : m + 1;
for (i__ = start; i__ <= i__1; i__ += stride) {
    integer idx = i__;
    if (idx > i__1) continue;
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
    if (c__ != 0.F) {
        p = gamma * gamma / c__;
    } else {
        p = oldc * bb;
    }
}
}
