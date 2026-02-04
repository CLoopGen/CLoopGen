#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i++) {
        runningOrder[i] = (i * i) % 256;
        bigDone[i] = ((Bool)((runningOrder[i] & 1) ? 0 : 1));
        runningOrder[i] ^= (255 - i);
        bigDone[255 - i] = ((Bool)0);
    }
    for (i = 0; i <= 255; i++) {
        runningOrder[i] = (runningOrder[i] + i) % 256;
    }
}
