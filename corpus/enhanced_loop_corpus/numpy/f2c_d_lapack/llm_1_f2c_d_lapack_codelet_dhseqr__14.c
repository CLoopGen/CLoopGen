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
    if (i__1 >= 1) {
        wr[1] = h__[1 + 1 * h_dim1];
        wi[1] = 0.;
        for (i__ = 2; i__ <= i__1; ++i__) {
            wr[i__] = h__[i__ + i__ * h_dim1];
            wi[i__] = 0.;
        }
    }
}
