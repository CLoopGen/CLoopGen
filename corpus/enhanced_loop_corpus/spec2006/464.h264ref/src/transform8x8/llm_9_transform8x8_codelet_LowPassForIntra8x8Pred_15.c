#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25; i++) {
        int val = LoopArray[i];
        PredPel[i] = val * val - 2 * val + 1; // (val - 1)^2 computed for higher arithmetic intensity
    }
}
