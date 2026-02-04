#include <stdio.h>

#include <inttypes.h>

extern int *PredPel;
extern int i;
extern int LoopArray[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25; i++) {
        if (i % 2 == 0) {
            LoopArray[i] = PredPel[i];
        } else {
            continue;
        }
    }
}
