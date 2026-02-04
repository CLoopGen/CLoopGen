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
    // Variant 1: Strided memory access with stride of 2
    // This changes the access pattern to skip every other element
    integer start = (1 >= *ihi) ? 1 : *ihi;
    for (i__ = start; i__ <= i__1; i__ += 2) {
        i__2 = i__;
        tau[i__2].r = 0.F;
        tau[i__2].i = 0.F;
    }
    // Handle potential odd index if i__1 is not aligned with stride
    if ((i__1 - start) % 2 == 1 && start <= i__1) {
        i__2 = i__1;
        tau[i__2].r = 0.F;
        tau[i__2].i = 0.F;
    }
}
