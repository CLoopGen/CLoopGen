#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *n;
extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= *n; j += 2) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        c__[i__3].r = 1.0F;
        c__[i__3].i = -1.0F;
    }
    if (j + 1 <= i__1) {
        for (i__ = j + 1; i__ <= *n; ++i__) {
            i__3 = i__ + (j + 1) * c_dim1;
            c__[i__3].r = 2.0F;
            c__[i__3].i = -2.0F;
        }
    }
}
}
