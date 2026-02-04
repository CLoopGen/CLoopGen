#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ihi;
extern real *h__;
extern real *wr;
extern real *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_wr;
    real temp_wi = 0.F;
    for (i__ = *ihi + 1; i__ <= i__1; ++i__) {
        temp_wr = h__[i__ + i__ * h_dim1];
        wr[i__] = temp_wr;
        wi[i__] = temp_wi;
    }
}
