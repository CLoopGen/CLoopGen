#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 25; i++) {
        LoopArray[i] = PredPel[i] + i * 2 - (i % 3);
        for (j = 0; j < 3; j++) {
            LoopArray[i] += (PredPel[i] + j) / (i + 1);
        }
    }
}
