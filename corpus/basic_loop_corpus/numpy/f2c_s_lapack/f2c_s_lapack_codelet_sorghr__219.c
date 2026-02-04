#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern integer *ihi;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = *ihi; j >= i__1; --j) {
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        a[i__ + j * a_dim1] = 0.F;
    }
    i__2 = *ihi;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        a[i__ + j * a_dim1] = a[i__ + (j - 1) * a_dim1];
    }
    i__2 = *n;
    for (i__ = *ihi + 1; i__ <= i__2; ++i__) {
        a[i__ + j * a_dim1] = 0.F;
    }
}

}
