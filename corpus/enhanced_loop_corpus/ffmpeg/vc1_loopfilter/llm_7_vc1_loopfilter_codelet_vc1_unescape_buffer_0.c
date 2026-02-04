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
    uint8_t prev_prev = 0, prev = 0, current;
    for (i = 0; i < size; i++) {
        current = src[i];
        // Introduce WAW dependency via staged writes and accumulate state
        if (current == 3 && i >= 2 && prev == 0 && prev_prev == 0 && i < size - 1 && src[i+1] < 4) {
            dst[dsize] = src[i+1];
            dsize++;
            dst[dsize] = 0; // Artificial WAW: write after prior write to dsize
            dsize++;
            prev_prev = prev;
            prev = current;
            if (i + 1 < size) {
                i++; // Skip the consumed lookahead element
                prev = src[i]; // Update dependency state
            }
        } else {
            dst[dsize] = current;
            dsize++;
            prev_prev = prev;
            prev = current;
        }
    }
}
