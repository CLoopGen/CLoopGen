#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *h__;
extern doublereal *wr;
extern doublereal *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 2; i__ <= i__1 - 1; i__ += 2) {
        wr[i__] = h__[i__ + i__ * h_dim1];
        wi[i__] = 0.;
        wr[i__ + 1] = h__[i__ + 1 + (i__ + 1) * h_dim1];
        wi[i__ + 1] = 0.;
    }
}
