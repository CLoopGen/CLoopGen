#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *vt;
extern real *vt2;
extern integer vt_dim1;
extern integer vt2_dim1;
extern integer i__1;
extern real c__;
extern integer i__;
extern integer m;
extern real s;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer step = 2;
for (i__ = nlp2; i__ <= i__1 - 1; i__ += step) {
    real val1 = vt[m + i__ * vt_dim1];
    real val2 = vt[m + (i__ + 1) * vt_dim1];
    vt2[i__ * vt2_dim1 + 1] = s * val1;
    vt2[(i__ + 1) * vt2_dim1 + 1] = s * val2;
    vt[m + i__ * vt_dim1] = c__ * val1;
    vt[m + (i__ + 1) * vt_dim1] = c__ * val2;
}
// Handle odd-sized range if needed with a scalar cleanup (not required if constraints guarantee even size)
if ((i__1 - nlp2 + 1) % 2 != 0) {
    vt2[i__ * vt2_dim1 + 1] = s * vt[m + i__ * vt_dim1];
    vt[m + i__ * vt_dim1] = c__ * vt[m + i__ * vt_dim1];
}
}
