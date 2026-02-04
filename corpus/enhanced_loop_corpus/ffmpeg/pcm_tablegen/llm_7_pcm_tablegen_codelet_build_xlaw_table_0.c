#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t base_val = 127 ^ mask;
    uint8_t inv_val = base_val ^ 255; 
    int offset;
    for (; j < 8192; j++) {
        offset = 8192 - j;
        linear_to_xlaw[offset] = inv_val;
        linear_to_xlaw[offset + (j << 1)] = base_val;
    }
}
