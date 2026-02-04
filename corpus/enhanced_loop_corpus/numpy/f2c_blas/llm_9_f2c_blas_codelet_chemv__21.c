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

extern singlecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    i__2 = i__;
    y[i__2].r = 1.F;
    y[i__2].i = -1.F;
    if (i__ + 1 <= i__1) {
        i__2 = i__ + 1;
        y[i__2].r = 2.F;
        y[i__2].i = -2.F;
    }
}
}
