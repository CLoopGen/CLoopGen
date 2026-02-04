#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 18; i < 24; i++) {
    if (i >= 21) {
        LoopArray[i] = ((&(PredPel[0]))[i - 1] + ((&(PredPel[0]))[i] << 1) + (&(PredPel[0]))[i + 1] + 2) >> 2;
    } else {
        LoopArray[i] = ((&(PredPel[0]))[i] << 1); // Different computation for early indices
    }
}
}
