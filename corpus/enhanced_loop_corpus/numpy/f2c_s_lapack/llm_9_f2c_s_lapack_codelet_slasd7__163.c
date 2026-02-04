#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *vf;
extern real *beta;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = nlp2; i__ <= i__1; i__ += 2) {
        z__[i__] = *beta * vf[i__];
        vf[i__] = 0.F;
        if (i__ + 1 <= i__1) {
            z__[i__ + 1] = *beta * vf[i__ + 1];
            vf[i__ + 1] = 0.F;
        }
    }
}
