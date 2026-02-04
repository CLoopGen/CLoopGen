#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *beta;
extern doublereal *vt;
extern integer vt_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        if (i__ % 2 == 0) {
            z__[i__] = *beta * vt[i__ + nlp2 * vt_dim1];
        } else {
            z__[i__] = 0.0;
        }
    }
}
