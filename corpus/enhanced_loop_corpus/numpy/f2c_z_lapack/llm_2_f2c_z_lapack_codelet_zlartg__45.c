#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *r__;
extern integer i__1;
extern doublecomplex z__1;
extern integer i__;
extern doublereal safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing with stride of 1
    doublecomplex *r_array = r__;
    for (i__ = 0; i__ < i__1; ++i__) {
        z__1.r = safmx2 * r_array[i__].r;
        z__1.i = safmx2 * r_array[i__].i;
        r_array[i__].r = z__1.r;
        r_array[i__].i = z__1.i;
    }
}
