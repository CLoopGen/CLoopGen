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
    real local_max = 0.0f;
    for (j = 1; j <= i__1; ++j) {
        real col_max = 0.0f;
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            r__1 = a[i__ + j * a_dim1];
            r__3 = (doublereal)((r__1) >= 0 ? (r__1) : -(r__1));
            col_max = (doublereal)(col_max >= r__3 ? col_max : r__3);
        }
        local_max = (doublereal)(local_max >= col_max ? local_max : col_max);
    }
    value = local_max;
}
