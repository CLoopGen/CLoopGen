#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *h__;
extern real *wr;
extern real *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_wr;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_wr = h__[i__ + i__ * h_dim1];
        wr[i__] = temp_wr;
        wi[i__] = 0.F;
    }
}
