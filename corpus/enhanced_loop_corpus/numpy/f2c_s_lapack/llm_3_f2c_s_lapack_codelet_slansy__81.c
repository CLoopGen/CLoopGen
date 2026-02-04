#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *n;
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
for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    ptrdiff_t base_index = j * a_dim1;
    for (i__ = j; i__ <= i__2; ++i__) {
        ptrdiff_t index = base_index + i__;
        r__2 = value;
        r__3 = (r__1 = a[index], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        value = (doublereal)((r__2) >= (r__3) ? (r__2) : (r__3));
    }
}
}
