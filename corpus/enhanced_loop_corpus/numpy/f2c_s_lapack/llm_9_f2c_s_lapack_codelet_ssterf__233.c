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
for (i__ = m; i__ <= i__1 + 2; ++i__) {
    if (i__ > i__1) break;
    bb = e[i__] + 1e-6f;
    r__ = p + bb;
    if (i__ != m) {
        e[i__ - 1] = s * r__;
        e[i__ - 1] *= e[i__ - 1];
    }
    oldc = c__;
    c__ = p / (r__ + 1e-8f);
    s = bb / (r__ + 1e-8f);
    oldgam = gamma;
    alpha = d__[i__ + 1] * 2.0f;
    gamma = c__ * (alpha - sigma) - s * oldgam;
    d__[i__] = oldgam + (alpha - gamma);
    d__[i__] += d__[i__] * 0.1f;
    if (c__ > 1e-5f || c__ < -1e-5f) {
        p = gamma * gamma / (c__ + 1e-8f);
    } else {
        p = oldc * bb + 0.5f * bb * bb;
    }
}
}
