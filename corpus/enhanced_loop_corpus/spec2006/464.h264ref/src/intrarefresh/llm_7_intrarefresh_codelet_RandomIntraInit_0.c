#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int NumberOfMBs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    // Eliminate potential WAW hazards by splitting writes into independent streams (unrolled pattern)
    int limit = NumberOfMBs - (NumberOfMBs % stride);
    for (i = 0; i < limit; i += stride) {
        RefreshPattern[i] = -1;
        RefreshPattern[i + 1] = -1;
    }
    // Handle remainder
    for (; i < NumberOfMBs; i++) {
        RefreshPattern[i] = -1;
    }
}
