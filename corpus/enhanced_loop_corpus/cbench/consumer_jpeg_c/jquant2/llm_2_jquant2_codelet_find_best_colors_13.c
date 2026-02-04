#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed traversal order (writing in reverse consecutive blocks)
    INT32 *temp = bptr;
    int size = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3));
    for (i = size - 1; i >= 0; i--) {
        temp[i] = 2147483647L;
    }
    bptr += size;  // Update original pointer to reflect advancement
}
