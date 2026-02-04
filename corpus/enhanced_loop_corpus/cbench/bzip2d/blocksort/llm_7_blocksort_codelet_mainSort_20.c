#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (i = 0, j = 255; i <= 255; i++, j--) {
        bigDone[i] = ((Bool)0);
        runningOrder[j] = i; // WAW dependence with potential conflict on runningOrder if reordered
    }
    // Eliminate direct sequential dependence by decoupling index from loop counter in one array
    // Introduces reverse-order write pattern, creating a loop-carried anti-dependence (WAR)
}
