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
        bigDone[temp[i]] = ((Bool)0); // Introduce indirect WAW via temp: Write after Write pattern through indexing
    }
    // Additional pass to create loop-carried dependence on previous iteration
    for (i = 1; i <= 255; i++) {
        runningOrder[i] = runningOrder[i-1] + 1; // Loop-carried dependence: each iteration depends on prior
    }
}
