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
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = i__ << 1;  // Double the index to increase stride
    i__3 = i__;
    if (i__2 <= i__1 * 2) {  // Adjusted bound to avoid out-of-bounds
        zy[i__2].r = zx[i__3].r + zx[i__3].i;  // Additional arithmetic: add imaginary part
        zy[i__2].i = zx[i__3].i - zx[i__3].r;  // Additional arithmetic: subtract real part
    }
}
}
