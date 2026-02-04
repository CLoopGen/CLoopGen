#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp = 0;
    for (i = 0; i < 23; i++) {
        temp = base[i];        // Read before write: create RAW dependency with next iteration if base[i] overlaps
        base[i] = temp + 1;    // WAW with previous base[i], and uses value read in same iteration (RAW)
        base[i] = base[i] - 1; // Additional WAW: two writes to same location in one iteration
    }
}
