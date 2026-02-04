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
if (i__1 >= 1 && *m >= 1) {
    i__2 = *m;
    i__3 = i__2 * i__1;
    for (i__ = 1; i__ <= i__3; ++i__) {
        j = (i__ - 1) / i__2 + 1;
        integer temp_i = (i__ - 1) % i__2 + 1;
        integer idx = temp_i + j * b_dim1;
        b[idx].r = 0.F;
        b[idx].i = 0.F;
    }
}
}
