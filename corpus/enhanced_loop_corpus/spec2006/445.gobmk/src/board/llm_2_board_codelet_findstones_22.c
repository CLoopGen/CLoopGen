#include <stdio.h>

#include <inttypes.h>

extern int next_stone[400];
extern int maxstones;
extern int *stones;
extern int size;
extern int pos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward)
    // We traverse only even indices in stones array, but still follow the linked structure via next_stone
    for (k = 0; k < maxstones && 2*k < size; k++) {
        stones[2*k] = pos;
        pos = next_stone[pos];
    }
}
