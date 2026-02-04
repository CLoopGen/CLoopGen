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
real temp_gamma, temp_c, temp_s, temp_p;
for (i__ = m - 1; i__ >= i__1; --i__) {
    bb = e[i__];
    r__ = p + bb;
    if (i__ != m - 1) {
        e[i__ + 1] = s * r__;
    }
    oldc = c__;
    temp_c = p / r__;
    temp_s = bb / r__;
    oldgam = gamma;
    alpha = d__[i__];
    temp_gamma = temp_c * (alpha - sigma) - temp_s * oldgam;
    d__[i__ + 1] = oldgam + (alpha - temp_gamma);
    temp_p = (temp_c != 0.F) ? (temp_gamma * temp_gamma / temp_c) : (oldc * bb);
    c__ = temp_c;
    s = temp_s;
    gamma = temp_gamma;
    p = temp_p;
}
}
