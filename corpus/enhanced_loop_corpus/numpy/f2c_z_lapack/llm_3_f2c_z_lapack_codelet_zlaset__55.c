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

extern doublecomplex *beta;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {
    integer row = i__ + 1;
    integer col = i__ + 1;
    integer idx = col + row * a_dim1; // Use column-major consecutive-like access pattern with offset
    a[idx].r = beta->r;
    a[idx].i = beta->i;
}
}
