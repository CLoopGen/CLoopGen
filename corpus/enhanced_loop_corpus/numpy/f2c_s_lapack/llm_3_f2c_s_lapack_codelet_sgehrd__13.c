#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ihi;
extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with offset-based access using pointer arithmetic
    real *base_tau = tau - ((1) >= (*ihi) ? (1) : (*ihi));
    integer start = ((1) >= (*ihi) ? (1) : (*ihi));
    for (i__ = start; i__ <= i__1; ++i__) {
        *(base_tau + i__) = 0.F;
    }
}
