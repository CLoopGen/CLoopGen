#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *cache;
extern int bits;
extern int i;
extern int low;
extern int high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with offset progression
    for (i = 0; i < 6; i++) {
        int offset = i; // Use loop index to create consecutive access pattern
        int addr = (low + offset) & 0xFF; // Simulate wrapping in a small address space
        if (cache[addr] >= bits)
            high = (high + low + 1) >> 1;
        else
            low = (high + low + 1) >> 1;
    }
}
