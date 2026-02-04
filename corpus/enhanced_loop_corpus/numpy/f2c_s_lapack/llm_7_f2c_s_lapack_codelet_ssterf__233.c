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
real temp_p = p;
for (i__ = m; i__ <= i__1; ++i__) {
    real local_bb = e[i__];
    real local_r__ = temp_p + local_bb;
    real local_c__ = temp_p / local_r__;
    real local_s = local_bb / local_r__;
    real local_alpha = d__[i__ + 1];
    real local_gamma = local_c__ * (local_alpha - sigma) - local_s * gamma;
    d__[i__] = gamma + (local_alpha - local_gamma);
    if (i__ != m) {
        e[i__ - 1] = local_s * local_r__;
    }
    if (local_c__ != 0.F) {
        temp_p = local_gamma * local_gamma / local_c__;
    } else {
        temp_p = c__ * local_bb;
    }
    c__ = local_c__;
    gamma = local_gamma;
}
p = temp_p;
}
