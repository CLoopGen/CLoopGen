#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_r = 0.F, temp_i = 0.F;
    for (i__ = 2; i__ <= i__1; ++i__) {
        i__2 = i__ + a_dim1;
        temp_r += a[i__2].r;
        temp_i += a[i__2].i;
        a[i__2].r = 0.F;
        a[i__2].i = 0.F;
    }
    // Introduce artificial dependency use to prevent dead code elimination
    if (i__1 < 2) {
        a[a_dim1 + 2].r = temp_r;
        a[a_dim1 + 2].i = temp_i;
    }
}
