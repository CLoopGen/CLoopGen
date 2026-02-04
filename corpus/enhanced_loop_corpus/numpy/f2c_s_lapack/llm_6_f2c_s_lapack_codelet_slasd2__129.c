#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *beta;
extern real *vt;
extern integer vt_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real beta_val = *beta;
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        z__[i__] = beta_val * vt[i__ + nlp2 * vt_dim1];
    }
}
