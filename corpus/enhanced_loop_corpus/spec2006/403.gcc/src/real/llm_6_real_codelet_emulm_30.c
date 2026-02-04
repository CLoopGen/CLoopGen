#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short b[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by splitting write operations
    // and introducing a temporary array to create write-after-write hazard across iterations
    unsigned short temp[9];
    for (i = 0; i < (6 + 3); i++) {
        temp[i] = equot[i];
    }
    for (i = 0; i < (6 + 3); i++) {
        b[i] = temp[i]; // WAW on b[i] if multiple passes were present; now safe but structured for dependency
    }
}
