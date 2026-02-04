#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2 (wrapping within bounds using modulo)
    for (i = 1; i < 5; i++) {
        int idx = (1 + 2 * (i - 1)) % 12; // Stride of 2 starting from index 1
        v = (v >> 16) | (v << 16);
        v *= keys[idx];
    }
}
