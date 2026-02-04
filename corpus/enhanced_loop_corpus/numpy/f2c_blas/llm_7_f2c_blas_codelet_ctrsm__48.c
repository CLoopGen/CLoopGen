#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern singlecomplex *b;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real temp_r, temp_i;
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    temp_r = (real)j * 0.5F;
    temp_i = (real)j * 1.5F;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * b_dim1;
        b[i__3].r = temp_r;
        b[i__3].i = temp_i;
    }
}
}
