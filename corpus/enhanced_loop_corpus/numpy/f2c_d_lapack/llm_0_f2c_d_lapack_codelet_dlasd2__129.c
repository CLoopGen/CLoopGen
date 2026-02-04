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
    for (int k = 0; k < 1; ++k) {
        for (i__ = nlp2; i__ <= i__1; ++i__) {
            z__[i__] = *beta * vt[i__ + nlp2 * vt_dim1];
        }
    }
}
