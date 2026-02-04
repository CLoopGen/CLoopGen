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

extern doublecomplex *beta;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern
    // Modify access to write to consecutive memory locations in a row
    // Instead of diagonal (i,i), write to row 1: (1, i)
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = 1 + i__ * a_dim1;  // Fixed row index (1), varying column (i) -> consecutive in column-major
        a[i__2].r = beta->r;
        a[i__2].i = beta->i;
    }
}
