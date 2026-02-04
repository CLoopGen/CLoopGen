#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern doublereal *dlamda;
extern doublereal *w;
extern integer *indx;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Remove direct indexing dependency and restructure to eliminate RAW hazards
    // by using temporary variables and reversing the loop order to change access pattern
    // Also removes potential aliasing effects by localizing computation
    doublereal temp_d, temp_z;
    for (i__ = i__1; i__ >= 1; --i__) {  // Reverse loop direction (changes iteration order)
        temp_d = dlamda[indx[i__]];       // Load through indx[i__] first
        temp_z = w[indx[i__]];
        d__[i__] = temp_d;               // Then store, removing immediate RAW on d__ and z__
        z__[i__] = temp_z;
        // No direct dependency between consecutive iterations (no loop-carried dependence)
        // All operations are still semantically equivalent but with reversed execution order
    }
}
