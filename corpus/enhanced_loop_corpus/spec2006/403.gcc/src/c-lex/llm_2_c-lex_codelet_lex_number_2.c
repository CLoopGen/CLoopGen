#include <stdio.h>

#include <inttypes.h>

extern unsigned int parts[16];
extern long high;
extern long low;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration and offset adjustment
    for (i = 0; i < (8 * 8) / 8; i++) {
        int idx_low = ((8 * 8) / 8) - 1 - i;  // Reverse order for low
        int idx_high = (8 * 8) - 1 - i;       // Reverse order for high
        low |= (long)parts[idx_low] << (i * 8);
        high |= (long)parts[idx_high] << (i * 8);
    }
}
