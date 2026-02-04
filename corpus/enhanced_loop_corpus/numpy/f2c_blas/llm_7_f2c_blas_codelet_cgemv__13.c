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
    real sum_r = 0.F, sum_i = 0.F;
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[i__].r = sum_r;
        y[i__].i = sum_i;
        sum_r += 1.F;
        sum_i += 1.F;
    }
}
