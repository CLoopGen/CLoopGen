#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_prev = 0, prev_curr = 0, curr_val;
    for (i = 0; i < size; i++) {
        curr_val = src[i];
        // Introduce artificial loop-carried dependence via rolling window variables
        if (curr_val == 3 && i >= 2 && prev_curr == 0 && prev_prev == 0 && i < size - 1 && src[i+1] < 4) {
            dst[dsize++] = src[i+1];
            // Update state with lookahead value to create WAW-like pattern
            prev_prev = prev_curr;
            prev_curr = src[i+1];
            i++; // Skip next index
        } else {
            dst[dsize++] = curr_val;
            prev_prev = prev_curr;
            prev_curr = curr_val;
        }
    }
}
