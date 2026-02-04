#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *work;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer stride = 4;
for (i__ = 1; i__ <= i__1; i__ += stride) {
    for (integer j = 0; j < stride && (i__ + j) <= i__1; ++j) {
        integer idx = i__ + j;
        r__1 = value, r__2 = work[idx];
        value = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
    }
}
}
