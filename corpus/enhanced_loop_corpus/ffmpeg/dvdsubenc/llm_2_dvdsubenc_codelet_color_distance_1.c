#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t a;
extern uint32_t b;
extern int r;
extern int d;
extern int i;
extern int alpha_a;
extern int alpha_b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory-like access using an array to simulate sequential data layout
    uint32_t temp_a = a;
    uint32_t temp_b = b;
    int shifts[4] = {24, 16, 8, 0}; // Predefined shift amounts accessed consecutively
    for (i = 0; i < 4; i++) {
        int shift = shifts[i];
        d = alpha_a * (int)((temp_a >> shift) & 255) - alpha_b * (int)((temp_b >> shift) & 255);
        r += d * d;
        alpha_a = temp_a >> 28;
        alpha_b = temp_b >> 28;
    }
}
