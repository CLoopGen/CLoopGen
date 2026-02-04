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
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element in the tau array starting from the initial index
    integer start = (1 >= *ihi) ? 1 : *ihi;
    for (i__ = start; i__ <= i__1; i__ += 2) {
        i__2 = i__;
        tau[i__2].r = 0. , tau[i__2].i = 0.;
    }
    // Handle any remaining odd index if range ends on an odd index and start was even
    if ((start % 2) == 0 && start <= i__1) {
        for (i__ = start + 1; i__ <= i__1; i__ += 2) {
            i__2 = i__;
            tau[i__2].r = 0. , tau[i__2].i = 0.;
        }
    }
}
