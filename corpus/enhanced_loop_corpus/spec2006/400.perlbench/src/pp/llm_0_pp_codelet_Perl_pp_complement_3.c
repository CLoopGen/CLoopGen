#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 i = 0; i < anum; i++) {
        *tmps = ~*tmps;
        tmps++;
    }
    anum = 0;
}
