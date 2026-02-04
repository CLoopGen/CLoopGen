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
    doublereal temp_wr;
    doublereal temp_wi;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_wr = h__[i__ + i__ * h_dim1];
        temp_wi = 0.;
        wr[i__] = temp_wr;
        wi[i__] = temp_wi;
    }
}
