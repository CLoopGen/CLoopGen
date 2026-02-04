#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int i;
extern IDWTELEM *dst;
extern IDWTELEM *src;
extern IDWTELEM *ref;
extern int w;
extern int mul;
extern int add;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant processes every second element, simulating a strided access pattern.
    // It ensures i remains within bounds by checking i+1 for ref array access.
    for (; i < w; i += 2) {
        if (i + 1 < w) {
            dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
        } else {
            // Handle edge case when i is the last index and i+1 is out of bounds
            dst[i] = src[i] - ((mul * (ref[i] + ref[i]) + add) >> shift);
        }
    }
}
