#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then offset)
    for (; i <= max; i += 2) {
        if (i <= max) todo[i] = 1;
    }
    for (I32 j = i - (max % 2 == 0 ? 1 : 2); j <= max; j += 2) {
        todo[j] = 1;
    }
}
