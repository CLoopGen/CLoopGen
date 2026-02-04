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
extern real safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing
    // Assume r__ points to the start of an array of singlecomplex elements
    singlecomplex *base_r = r__;  // Base pointer for consecutive access
    for (i__ = 0; i__ < i__1; ++i__) {
        singlecomplex temp;
        temp.r = safmn2 * base_r[i__].r;
        temp.i = safmn2 * base_r[i__].i;
        base_r[i__].r = temp.r;
        base_r[i__].i = temp.i;
    }
}
