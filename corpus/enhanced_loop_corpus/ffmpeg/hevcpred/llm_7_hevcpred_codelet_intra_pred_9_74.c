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
    uint16_t prev_val = 0;
    for (i = 2 * size - 2; i >= 0; i--) {
        uint16_t current_input = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        filtered_left[i] = current_input ^ prev_val;
        prev_val = current_input;
    }
}
