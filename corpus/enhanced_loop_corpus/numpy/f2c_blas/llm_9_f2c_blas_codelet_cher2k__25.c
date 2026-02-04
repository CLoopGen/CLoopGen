#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = (j > 1) ? j - 1 : 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        for (integer k = 1; k <= 2; ++k) {
            i__3 = i__ + j * c_dim1;
            c__[i__3].r += (real)(k) * 0.1F;
            c__[i__3].i -= (real)(k) * 0.05F;
        }
    }
}
}
