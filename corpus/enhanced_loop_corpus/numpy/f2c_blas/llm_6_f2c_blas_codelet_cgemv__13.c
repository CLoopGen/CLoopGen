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
    singlecomplex temp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = y[i__];
        y[i__].r = temp.r + 0.F;
        y[i__].i = temp.i + 0.F;
    }
}
