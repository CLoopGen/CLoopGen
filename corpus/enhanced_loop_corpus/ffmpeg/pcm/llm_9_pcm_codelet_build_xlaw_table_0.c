#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 8192;
    for (; j < limit; j++) {
        uint8_t computed_mask1 = (uint8_t)(127 ^ (mask ^ 128)) + (uint8_t)(j % 3);
        uint8_t computed_mask2 = (uint8_t)(127 ^ mask) + (uint8_t)((j + 5) % 3);
        linear_to_xlaw[8192 - j] = computed_mask1;
        linear_to_xlaw[8192 + j] = computed_mask2;
        linear_to_xlaw[8193 - j] = (uint8_t)(computed_mask1 ^ 1);
        linear_to_xlaw[8191 + j] = (uint8_t)(computed_mask2 ^ 1);
    }
}
