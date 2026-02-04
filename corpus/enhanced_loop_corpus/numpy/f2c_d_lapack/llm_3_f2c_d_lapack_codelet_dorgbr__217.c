#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every second element instead of consecutive ones
    // This increases stride in the access pattern, modifying spatial locality
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        a[i__ + a_dim1] = 0.;
    }
}
