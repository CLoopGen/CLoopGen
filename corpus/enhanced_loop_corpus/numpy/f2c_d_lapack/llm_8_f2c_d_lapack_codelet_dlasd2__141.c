#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *vt;
extern doublereal *vt2;
extern integer vt_dim1;
extern integer vt2_dim1;
extern integer i__1;
extern doublereal c__;
extern integer i__;
extern integer m;
extern doublereal s;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        vt2[i__ * vt2_dim1 + 1] = s * vt[m + i__ * vt_dim1];
        vt[m + i__ * vt_dim1] = c__ * vt[m + i__ * vt_dim1];
        if (i__ > nlp2) {
            vt2[(i__-1) * vt2_dim1 + 2] += s * vt[m + (i__-1) * vt_dim1];
        }
    }
}
