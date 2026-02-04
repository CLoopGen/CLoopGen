#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp[256];
    for (i = 0; i <= 255; i++) {
        runningOrder[i] = i;
        temp[i] = runningOrder[i]; // Introduce WAR dependency: Write after Read on runningOrder
        bigDone[i] = ((Bool)0);
    }
    // Additional use of temp to prevent elimination (simulated work)
    for (i = 0; i <= 255; i++) {
        bigDone[temp[i]] = ((Bool)1); // Create loop-carried dependence via temp indexing
    }
}
