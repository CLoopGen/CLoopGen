#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *n1;
extern integer *indxq;
extern integer i__1;
extern integer i__;
extern integer n1p1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    integer base_index = n1p1 - 1; // Base offset
    for (i__ = 0; i__ <= i__1 - n1p1; ++i__) {
        integer actual_index = base_index + i__ + 1; // Simulate indirect lookup
        indxq[actual_index] += *n1;
    }
}
