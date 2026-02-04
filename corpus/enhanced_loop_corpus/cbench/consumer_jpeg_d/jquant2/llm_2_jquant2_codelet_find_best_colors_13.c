#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed direction
    INT32 *start = bptr;
    int size = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3));
    for (i = 0; i < size; i++) {
        start[i] = 2147483647L;
    }
    bptr += size; // Update bptr to reflect advancement
}
