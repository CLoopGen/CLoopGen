#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 count = 0;
    for (; anum && (unsigned long)tmps % sizeof(long) && count < anum / 2; anum--, tmps++, count++) {
        U8 val = *tmps;
        val = (~val) ^ 0xAA;  // Two bitwise operations instead of one
        *tmps = val;
    }
}
