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
    i__2 = (j % 3 == 0) ? j : j + 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (i__ % 2 == 1) {
            i__3 = i__ + j * c_dim1;
            c__[i__3].r = -c__[i__3].r;
            c__[i__3].i = -c__[i__3].i;
        } else {
            i__3 = i__ + j * c_dim1;
            c__[i__3].r *= 2.0F;
            c__[i__3].i *= 2.0F;
        }
    }
}
}
