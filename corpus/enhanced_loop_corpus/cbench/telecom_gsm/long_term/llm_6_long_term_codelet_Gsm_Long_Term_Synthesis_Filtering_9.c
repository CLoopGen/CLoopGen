#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *drp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency
    // by splitting the write into two steps with an intermediate assignment.
    // This creates a dependence where each iteration waits on the previous one.
    word temp[120];
    for (k = 0; k <= 119; k++) {
        temp[k] = drp[-80 + k];  // Stage 1: Read and store in temp
    }
    for (k = 0; k <= 119; k++) {
        drp[-120 + k] = temp[k];  // Stage 2: Write from temp, creating artificial WAW chain if optimized poorly
    }
}
