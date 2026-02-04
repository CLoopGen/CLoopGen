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
for (i__ = m; i__ <= i__1; ++i__) {
    bb = e[i__];
    r__ = p + bb;
    oldc = c__;
    c__ = p / r__;
    s = bb / r__;
    if (i__ > m) {
        e[i__ - 1] = s * r__;
    }
    oldgam = gamma;
    alpha = d__[i__ + 1];
    gamma = c__ * (alpha - sigma) - s * oldgam;
    d__[i__] = oldgam + (alpha - gamma);
    if (c__ == 0.F) {
        p = oldc * bb;
        continue;
    }
    p = gamma * gamma / c__;
}
}
