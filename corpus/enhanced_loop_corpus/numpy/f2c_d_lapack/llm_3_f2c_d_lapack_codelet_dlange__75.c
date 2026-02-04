#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 4
    // This accesses every 4th element in multiple passes to simulate strided pattern
    integer i__;
    integer stride = 4;
    for (integer pass = 0; pass < stride; ++pass) {
        for (i__ = 1 + pass; i__ <= i__1; i__ += stride) {
            work[i__] = 0.;
        }
    }
}
