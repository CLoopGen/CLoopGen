#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__3 = j + 1;
    i__2 = ((i__3) <= (*m) ? (i__3) : (*m));
    for (integer k = 1; k <= i__2; ++k) {
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] *= mul;
        }
    }
}
}
