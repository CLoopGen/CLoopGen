#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k2;
extern integer k3;
extern integer k4;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= k4; ++j) {
    i__3 = k1 - j;
    i__2 = (k3 < (k4 - j)) ? k3 : (k4 - j);
    if (i__3 > i__2) continue;
    for (i__ = i__3; i__ <= i__2; ++i__) {
        if (i__ >= k2) {
            a[i__ + j * a_dim1] *= mul;
        }
    }
}
}
