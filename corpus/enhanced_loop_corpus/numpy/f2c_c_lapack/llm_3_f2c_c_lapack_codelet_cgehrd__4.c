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

extern integer *ihi;
extern singlecomplex *tau;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal
    // Access elements from i__1 down to max(1, *ihi), in descending order
    integer start = (*ihi > 1) ? *ihi : 1;
    for (i__ = i__1; i__ >= start; --i__) {
        i__2 = i__;
        tau[i__2].r = 0.F;
        tau[i__2].i = 0.F;
    }
}
