#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *local_ptr = ptr;
    uint32 count = (1L << 5) * (1L << 5) * (1L << 5);
    for (uint32 j = 0; j < count; j++) {
        *(local_ptr + j) = 0; // Eliminate pointer update side effect; no loop-carried dependency
    }
    ptr = local_ptr + count; // Update ptr only once after loop
}
