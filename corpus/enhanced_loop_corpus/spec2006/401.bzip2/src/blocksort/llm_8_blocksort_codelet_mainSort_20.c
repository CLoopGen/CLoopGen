#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 2) {
        bigDone[i] = ((Bool)0);
        runningOrder[i] = i;
        if (i + 1 < 256) {
            bigDone[i + 1] = ((Bool)0);
            runningOrder[i + 1] = i + 1;
        }
    }
}
