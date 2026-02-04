#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f0;
extern int Y0;
extern int Y1;
extern uint8_t Luma[16];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order (strided by -1)
    for (mask = 128, i = 0; mask; mask >>= 1, i++) {
        int index = 15 - i;  // Reverse the index to write consecutively from end
        if (f0 & mask)
            Luma[index] = Y1;
        else
            Luma[index] = Y0;
    }
}
