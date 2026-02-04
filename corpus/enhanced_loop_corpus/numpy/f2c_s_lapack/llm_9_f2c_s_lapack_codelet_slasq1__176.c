#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer step = 2;
for (i__ = 1; i__ <= i__1; i__ += step) {
    r__1 = sigmx;
    r__2 = d__[i__];
    sigmx = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
    if (i__ + 1 <= i__1) {
        r__1 = sigmx;
        r__2 = d__[i__ + 1];
        sigmx = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
    }
}
}
