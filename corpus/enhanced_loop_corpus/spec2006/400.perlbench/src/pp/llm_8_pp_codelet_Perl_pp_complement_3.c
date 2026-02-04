#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 count = anum;
    for (; count > 0; count -= 2, tmps += 2) {
        if (count >= 2) {
            *tmps = ~*tmps;
            *(tmps + 1) = ~*(tmps + 1);
        } else {
            *tmps = ~*tmps;
        }
    }
}
