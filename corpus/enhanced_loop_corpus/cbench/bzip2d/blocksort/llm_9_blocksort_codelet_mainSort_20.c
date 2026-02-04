#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 511; i++) {
        Int32 idx = i >> 1;
        if (idx < 256) {
            bigDone[idx] = ((Bool)0);
            runningOrder[idx] = idx;
        }
    }
}
