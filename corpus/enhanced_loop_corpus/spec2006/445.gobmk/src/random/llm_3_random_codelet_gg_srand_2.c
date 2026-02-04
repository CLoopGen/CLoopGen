#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[25];
extern unsigned int seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (access array from end to start)
    for (i = 0; i < 25; i++) {
        int index = 24 - i;  // Traverse array in reverse order
        x[index] = seed;
        seed *= 1313;
        seed += 88897;
    }
}
