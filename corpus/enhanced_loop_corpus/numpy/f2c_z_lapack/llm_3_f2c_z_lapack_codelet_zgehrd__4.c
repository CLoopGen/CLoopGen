#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *ihi;
extern doublecomplex *tau;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the same range but in reverse order to modify memory access pattern
    integer start = (1 >= *ihi) ? 1 : *ihi;
    for (i__ = i__1; i__ >= start; --i__) {
        i__2 = i__;
        tau[i__2].r = 0. , tau[i__2].i = 0.;
    }
}
