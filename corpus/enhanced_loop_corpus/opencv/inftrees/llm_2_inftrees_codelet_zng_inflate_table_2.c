#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every other element starting from max)
    for (max = 15; max >= 1; max -= 2) {
        if (count[max] != 0)
            break;
        // Check intermediate index if stride skips it, ensuring full coverage
        if (max > 1 && count[max - 1] != 0) {
            max--;  // Adjust max to reflect correct position
            break;
        }
    }
}
