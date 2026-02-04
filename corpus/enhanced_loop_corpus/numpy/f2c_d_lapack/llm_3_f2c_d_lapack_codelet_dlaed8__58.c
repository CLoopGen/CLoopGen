#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer *cutpnt;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    integer base_index = *cutpnt + 1;
    for (i__ = 0; i__ <= i__1 - base_index; ++i__) {
        integer actual_index = base_index + i__; // indirect-like indexing via offset
        indxq[actual_index] += *cutpnt;
    }
}
