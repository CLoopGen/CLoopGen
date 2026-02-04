#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_val = 0;
    for (i = 2 * size - 2; i >= 0; i--) {
        uint8_t current_contrib = (2 * left[i]) >> 2;
        uint8_t neighbor_avg = (left[i + 1] + left[i - 1] + 2) >> 2;
        filtered_left[i] = current_contrib + neighbor_avg;
        prev_val = filtered_left[i];
    }
}
