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
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    real temp1 = vt[nlp1 + i__ * vt_dim1];
    vt[m + i__ * vt_dim1] = -s * temp1;
    vt2[i__ * vt2_dim1 + 1] = c__ * temp1;

    if (i__ + 1 <= i__1) {
        real temp2 = vt[nlp1 + (i__ + 1) * vt_dim1];
        vt[m + (i__ + 1) * vt_dim1] = -s * temp2;
        vt2[(i__ + 1) * vt2_dim1 + 1] = c__ * temp2;
    }
}
}
