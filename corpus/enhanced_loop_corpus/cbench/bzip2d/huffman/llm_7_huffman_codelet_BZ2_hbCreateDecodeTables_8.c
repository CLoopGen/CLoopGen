#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce artificial WAW (write-after-write) and WAR (write-after-read) dependencies
    // Simulate additional data dependencies using temporary array to delay updates
    Int32 temp[23];
    
    // First, read all values to break immediate loop-carried RAW chain
    for (i = 0; i < 23; i++) {
        temp[i] = base[i];
    }

    // Now update with delayed writes — introduces WAW and WAR via temp usage
    for (i = 1; i < 23; i++) {
        base[i] = temp[i] + temp[i - 1];  // All reads from temp break direct base[i-1] -> base[i] flow
    }
}
