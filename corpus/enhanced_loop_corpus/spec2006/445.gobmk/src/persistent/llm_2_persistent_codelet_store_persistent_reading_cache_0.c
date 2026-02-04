#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection shadow[400];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset and stride of 2
    int start = 19 + 2;
    int end = (19 + 1) * (19 + 1);
    for (k = start; k < end; k += 2)
        active[k] = shadow[k];
    // Handle remaining index if end - start is odd
    if ((end - start) % 2 != 0 && (end - 1) % 2 == 1)
        active[end - 1] = shadow[end - 1];
}
