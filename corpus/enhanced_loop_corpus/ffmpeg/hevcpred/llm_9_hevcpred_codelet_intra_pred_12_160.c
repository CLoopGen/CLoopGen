#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *left;
extern uint16_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2 * size - 3; i >= 1; i--) {
        uint32_t sum = (uint32_t)(left[i + 1]) + (uint32_t)(left[i]) + (uint32_t)(left[i]) +
                       (uint32_t)(left[i - 1]) + 3;
        filtered_left[i] = sum >> 2;
    }
}
