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
    // Variant 1: Consecutive memory access by reordering index calculation
    // Instead of accessing column-major like elements (i__ + a_dim1), we access consecutive elements starting from a[2 + a_dim1]
    integer start_index = 2 + a_dim1;
    integer end_index = i__1 + a_dim1;
    for (i__ = start_index; i__ <= end_index; ++i__) {
        a[i__].r = 0.F;
        a[i__].i = 0.F;
    }
}
