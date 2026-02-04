#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward iteration
    // Instead of accessing symmetric indices around 8192, we write consecutively to two separate regions
    // First half: [8193, 16384] filled with (127 ^ mask), Second half: [1, 8192] filled with (127 ^ (mask ^ 128)) in reverse order
    uint8_t val1 = (127 ^ (mask ^ 128));
    uint8_t val2 = (127 ^ mask);
    for (; j < 8192; j++) {
        linear_to_xlaw[8193 + j] = val2;
        linear_to_xlaw[8192 - j] = val1;
    }
}
