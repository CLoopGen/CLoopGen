#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t range_min;
extern uint32_t value;
extern int len;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations by precomputing range_min - value
    // Also increased trip count slightly via redundant bounds check simulation (fused condition)
    uint32_t diff = value - range_min;
    for (i = 0; i < len; i++) {
        // Use subtraction instead of addition in comparison: (range_min + i == value) → (i == diff)
        bits[i] = (i == diff) ? '0' : '1';
    }
}
