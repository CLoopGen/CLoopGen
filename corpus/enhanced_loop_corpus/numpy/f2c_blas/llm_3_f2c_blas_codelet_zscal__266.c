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

extern doublecomplex *za;
extern doublecomplex *zx;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {  // Shifted index base for consecutive forward access
    i__2 = i__;
    i__3 = i__; 
    z__1.r = za->r * zx[i__3].r - za->i * zx[i__3].i , z__1.i = za->r * zx[i__3].i + za->i * zx[i__3].r;
    zx[i__2 + 1].r = z__1.r , zx[i__2 + 1].i = z__1.i;  // Store result in next position (consecutive write)
}
}
