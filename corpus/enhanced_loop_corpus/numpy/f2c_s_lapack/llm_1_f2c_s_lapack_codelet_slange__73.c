#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern integer j;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && *m >= 1; ++j) {
    i__ = 1;
    r__2 = value , r__3 = (r__1 = a[i__ + j * a_dim1] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    value = (doublereal)((r__2) >= (r__3) ? (r__2) : (r__3));
}
}
