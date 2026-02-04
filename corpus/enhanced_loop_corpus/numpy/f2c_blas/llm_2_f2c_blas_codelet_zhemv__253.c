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
for (i__ = 1; i__ <= i__1; i__ += 2) {
    i__2 = i__;
    y[i__2].r = 0. , y[i__2].i = 0.;
    if (i__ + 1 <= i__1) {
        i__2 = i__ + 1;
        y[i__2].r = 0. , y[i__2].i = 0.;
    }
}
}
