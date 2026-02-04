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

extern singlecomplex *r__;
extern integer i__1;
extern singlecomplex q__1;
extern integer i__;
extern real safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing
    singlecomplex *r_array = r__;
    for (i__ = 0; i__ < i__1; ++i__) {
        q__1.r = safmx2 * r_array[i__].r;
        q__1.i = safmx2 * r_array[i__].i;
        r_array[i__].r = q__1.r;
        r_array[i__].i = q__1.i;
    }
}
