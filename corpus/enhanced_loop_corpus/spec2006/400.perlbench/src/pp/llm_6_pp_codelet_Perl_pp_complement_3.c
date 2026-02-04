#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    U8 value;
    for (; anum > 0; anum--, tmps++) {
        value = ~*tmps;
        *tmps = value;
    }
}
