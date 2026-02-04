#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf1;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_state = state;
    for (k = 0; k < 320 * 240; k++) {
        temp_state = temp_state * 1664525 + 1013904223;
        buf1[k] = temp_state >> 24;
    }
    state = temp_state; // Remove loop-carried dependency on global 'state' during iterations, update only at end
}
