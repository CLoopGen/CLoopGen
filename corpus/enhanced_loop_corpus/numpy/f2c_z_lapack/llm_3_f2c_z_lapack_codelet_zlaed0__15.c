#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer *iwork;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern integer smm1;
extern integer submat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Step
    // This variant changes the access pattern to process elements with a stride of 2,
    // effectively splitting the loop into even and odd phases. Here we process indices
    // in a strided manner: first even, then odd, or vice versa. This can help in 
    // scenarios with memory bank conflicts or prefetching optimization.
    integer i__;
    // First pass: Stride of 2 starting at 1 (odd indices)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        d__[smm1] -= (d__1 = e[smm1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        d__[submat] -= (d__1 = e[smm1], ((d__1) >= 0 ? (d__1) : -(d__1)));
    }
    // Second pass: Stride of 2 starting at 2 (even indices)
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        submat = iwork[i__] + 1;
        smm1 = submat - 1;
        d__[smm1] -= (d__1 = e[smm1], ((d__1) >= 0 ? (d__1) : -(d__1)));
        d__[submat] -= (d__1 = e[smm1], ((d__1) >= 0 ? (d__1) : -(d__1)));
    }
}
