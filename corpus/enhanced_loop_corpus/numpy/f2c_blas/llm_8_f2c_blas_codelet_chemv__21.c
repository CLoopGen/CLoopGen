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

extern singlecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    for (integer j = 0; j < 4; ++j) {
        y[i__].r += (real)(j * 2) * 0.5F;
        y[i__].i -= (real)(j * 3) * 0.25F;
    }
}
}
