#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublecomplex acc;
    acc.r = 0.0;
    acc.i = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        acc.r += y[i__].r;
        acc.i += y[i__].i;
        i__2 = i__;
        y[i__2].r = acc.r;
        y[i__2].i = acc.i;
    }
}
