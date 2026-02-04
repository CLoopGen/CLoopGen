#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (i = 63; i >= 0; i--)
        coordmap[63 - i] = (i & 7) + (i >> 3) * stride;
}
