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
    // Variant 2: Consecutive forward access using temporary array indexing to simulate indirect-like pattern
    uint8_t* temp_filtered = filtered_left + 2 * size - 2;
    uint8_t* temp_left = left;

    for (i = 0; i < 2 * size - 1; i++) {
        int idx = 2 * size - 2 - i; // Reverse index to maintain same element order as original
        temp_filtered[-i] = (temp_left[idx + 1] + 2 * temp_left[idx] + temp_left[idx - 1] + 2) >> 2;
    }
}
