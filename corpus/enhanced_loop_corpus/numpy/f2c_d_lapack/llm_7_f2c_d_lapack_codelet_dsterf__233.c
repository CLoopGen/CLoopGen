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
doublereal temp_p = p;
for (i__ = m; i__ <= i__1; ++i__) {
    doublereal local_bb = e[i__];
    doublereal local_r = temp_p + local_bb;
    if (i__ != m) {
        e[i__ - 1] = s * local_r;
    }
    doublereal local_c = temp_p / local_r;
    doublereal local_s = local_bb / local_r;
    doublereal local_gamma = local_c * (d__[i__ + 1] - sigma) - local_s * gamma;
    d__[i__] = gamma + (d__[i__ + 1] - local_gamma);
    if (local_c != 0.0) {
        temp_p = local_gamma * local_gamma / local_c;
    } else {
        temp_p = c__ * local_bb;
    }
    c__ = local_c;
    s = local_s;
    gamma = local_gamma;
}
p = temp_p;
}
