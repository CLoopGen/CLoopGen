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
    singlecomplex temp;
    for (i__ = 2; i__ <= i__1; ++i__) {
        i__2 = i__ + a_dim1;
        temp.r = a[i__2 - 1].r + 1.0F;
        temp.i = a[i__ - 1 + a_dim1].i + 1.0F;
        a[i__2].r = temp.r;
        a[i__2].i = temp.i;
    }
}
