#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access)
    int indices[25];
    for (i = 0; i < 25; i++)
        indices[i] = 24 - i;  // Reverse mapping: process array from end to start
    for (i = 0; i < 25; i++)
        LoopArray[i] = PredPel[indices[i]];
}
