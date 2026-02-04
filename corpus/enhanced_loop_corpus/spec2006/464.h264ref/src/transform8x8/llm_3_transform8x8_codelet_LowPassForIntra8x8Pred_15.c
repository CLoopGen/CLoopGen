#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated with fixed offset pattern)
    int indices[25];
    for (int j = 0; j < 25; j++) {
        indices[j] = 24 - j;  // Reverse order access: process array from end to start
    }
    for (i = 0; i < 25; i++) {
        int idx = indices[i];
        PredPel[i] = LoopArray[idx];
    }
}
