#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f1;
extern int Y0;
extern int Y1;
extern uint8_t Luma[16];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing
    int base_index = 8;
    for (mask = 128, i = 0; mask; mask >>= 1, i++) {
        if (f1 & mask)
            Luma[base_index + i] = Y1;
        else
            Luma[base_index + i] = Y0;
    }
}
