#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency
    // by splitting the initialization into two passes with a control dependency.
    for (i = 53 - 1; i >= 0; i--) {
        reg_set_luid[i] = 1;  // First write
    }
    for (i = 53 - 1; i >= 0; i--) {
        reg_set_luid[i] = 0;  // Second write, creates WAW dependency across iterations if reordered
    }
}
