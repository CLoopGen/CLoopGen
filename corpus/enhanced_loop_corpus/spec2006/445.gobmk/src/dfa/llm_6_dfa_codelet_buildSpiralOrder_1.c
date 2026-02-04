#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce WAW (Write-After-Write) dependency and loop-carried dependence
    // by splitting the initialization into two stages with a sequential dependency
    for (i = 21; i < 21 * 3; i++) {
        for (j = 21; j < 21 * 3; j++) {
            int index = 4 * 21 * i + j;
            mark[index] = -1;  // First write creates WAW dependency
        }
    }
    for (i = 21; i < 21 * 3; i++) {
        for (j = 21; j < 21 * 3; j++) {
            int index = 4 * 21 * i + j;
            mark[index] = 0;   // Second write depends on first -> WAW, loop-carried across outer loops
        }
    }
}
