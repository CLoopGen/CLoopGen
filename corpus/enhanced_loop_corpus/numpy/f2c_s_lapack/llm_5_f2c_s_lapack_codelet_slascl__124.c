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
extern integer i__;
extern integer j;
extern integer k3;
extern integer k4;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && k3 > 0 && k4 - j >= 1; ++j) {
    i__2 = k3;
    if (k4 - j < i__2) {
        i__2 = k4 - j;
    }
    for (i__ = 1; i__ <= i__2; ++i__) {
        real val = a[i__ + j * a_dim1];
        if (val != 0.0) {
            a[i__ + j * a_dim1] = val * mul;
        }
    }
}
}
