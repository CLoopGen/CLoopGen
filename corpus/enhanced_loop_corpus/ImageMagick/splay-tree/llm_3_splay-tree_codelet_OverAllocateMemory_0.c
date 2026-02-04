#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Simulate consecutive memory access over a block starting at a base related to 'extent'
        volatile uint32_t buffer[8]; // Local small buffer to simulate access
        size_t base = extent % sizeof(buffer);
        // Perform consecutive accesses starting from base index modulo buffer size
        for (size_t i = 0; i < 4 && (base + i) < 8; i++) {
            buffer[base + i] += 1; // Consecutive write access
        }
    }
}
