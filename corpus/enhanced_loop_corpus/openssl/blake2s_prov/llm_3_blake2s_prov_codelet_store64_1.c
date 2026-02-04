#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive read-like pattern using a temporary array to simulate reordering
    uint8_t temp[8];
    for (i = 0; i < 8; i++) {
        temp[i] = (uint8_t)(w >> (8 * (7 - i)));  // Load bytes in reverse byte order
    }
    // Write consecutively to p in natural order (simulates reordered access via buffer)
    for (i = 0; i < 8; i++) {
        p[i] = temp[i];
    }
}
