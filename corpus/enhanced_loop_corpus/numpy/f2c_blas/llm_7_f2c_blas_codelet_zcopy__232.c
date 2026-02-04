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

extern doublecomplex *zx;
extern doublecomplex *zy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublereal temp_r, temp_i;
for (i__ = 1; i__ <= i__1; ++i__) {
    temp_r = zx[i__].r;
    temp_i = zx[i__].i;
    zy[i__].r = temp_r;
    zy[i__].i = temp_i;
}
}
