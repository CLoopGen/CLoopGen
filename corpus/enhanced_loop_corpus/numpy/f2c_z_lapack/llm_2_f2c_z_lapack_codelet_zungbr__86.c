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

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing a[i__ + a_dim1] for i__ from 2 to i__1,
    // we rewrite the loop to traverse a consecutive segment of the array
    // assuming a row-major layout and that a_dim1 is a stride.
    integer start_index = 2 + a_dim1;
    integer end_index = i__1 + a_dim1;
    for (i__ = start_index; i__ <= end_index; ++i__) {
        a[i__].r = 0.0;
        a[i__].i = 0.0;
    }
}
