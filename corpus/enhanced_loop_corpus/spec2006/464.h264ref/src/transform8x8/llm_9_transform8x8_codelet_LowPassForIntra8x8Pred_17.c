#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 18; i < 25; i++) {
        int p0 = (&(PredPel[0]))[i - 1];
        int p1 = (&(PredPel[0]))[i];
        int p2 = (&(PredPel[0]))[i + 1];
        LoopArray[i] = (p0 + (p1 << 2) + p2 + 4) >> 3;
    }
}
