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
    if (i__ <= i__1) {
        y[i__].r = 1.0F;
        y[i__].i = -1.0F;
    }
    integer i_temp = i__ + 1;
    if (i_temp <= i__1) {
        y[i_temp].r = 2.0F;
        y[i_temp].i = -2.0F;
    }
}
}
