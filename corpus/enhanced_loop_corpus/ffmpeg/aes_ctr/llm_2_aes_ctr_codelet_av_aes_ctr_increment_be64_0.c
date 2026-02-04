#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *counter;
extern uint8_t *cur_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping appropriately)
    uint8_t *start = counter;
    uint8_t *pos = start + 6; // Adjust to stay within bounds when using stride
    for (int i = 3; i >= 0; i--) {
        uint8_t *cur = pos - i * 2;
        if (cur < start) continue;
        (*cur)++;
        if (*cur != 0) {
            break;
        }
    }
}
