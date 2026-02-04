#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *q;
extern integer q_dim1;
extern integer i__1;
extern integer i__;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write, indirect read using offset array
    // Simulate indirect access pattern by introducing a small lookup offset
    // Here we maintain logical equivalence but access via a shifted base
    integer base_offset = q_dim1;
    integer target_offset = ktemp * q_dim1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        // Access pattern becomes more scattered in effective address calculation
        q[i__ + target_offset] = q[(i__ << 0) + base_offset]; // Logical identity, but emphasizes arithmetic form
    }
}
