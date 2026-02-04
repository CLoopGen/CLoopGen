#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf1;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[320 * 240];
    for (int i = 0; i < 320 * 240; i++) {
        indices[i] = i;
    }
    // Reverse access pattern (indirect via reversed index array)
    for (k = 0; k < 320 * 240; k++) {
        int idx = indices[320 * 240 - 1 - k]; // Indirect, reverse order
        state = state * 1664525 + 1013904223;
        buf1[idx] = state >> 24;
    }
}
