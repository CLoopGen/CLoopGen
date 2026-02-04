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
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer *indices = (integer*)malloc(i__1 * sizeof(integer));
if (indices == NULL) return;
for (i__ = 0; i__ < i__1; ++i__) {
    indices[i__] = iy + i__ * (*incy);
}
for (i__ = 0; i__ < i__1; ++i__) {
    integer idx = indices[i__];
    y[idx].r = 0.0;
    y[idx].i = 0.0;
}
free(indices);
}
