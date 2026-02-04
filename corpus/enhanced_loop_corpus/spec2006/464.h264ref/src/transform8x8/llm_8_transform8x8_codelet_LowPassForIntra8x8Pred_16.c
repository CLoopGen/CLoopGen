#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 17; i++) {
    LoopArray[i] = ((&(PredPel[0]))[i - 1] + ((&(PredPel[0]))[i] << 2) + (&(PredPel[0]))[i + 1] + 4) >> 3;
}
}
