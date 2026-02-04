#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 outer = anum >> 1; outer > 0; outer--) {
        for (I32 inner = 0; inner < 2 && anum > 0; inner++, anum--, tmps++) {
            *tmps = ~*tmps;
        }
    }
    if (anum > 0) {
        *tmps = ~*tmps;
    }
}
