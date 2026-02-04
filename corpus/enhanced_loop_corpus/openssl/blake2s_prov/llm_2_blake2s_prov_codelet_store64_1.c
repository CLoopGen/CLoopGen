#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse order (stride of 2, alternating direction)
    for (i = 0; i < 8; i++) {
        int index = 7 - i;  // Reverse traversal
        p[2 * index] = (uint8_t)(w >> (8 * i));  // Strided write (every 2nd element)
    }
}
