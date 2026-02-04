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
    // Reduce effective trip count by skipping predictable patterns early
    // Increase arithmetic operations per iteration with bounds-checked lookahead
    for (i = 0; i < size; i++) {
        uint8_t val = src[i];
        int condition = (val == 3) && (i >= 2) && (src[i-1] == 0) && (src[i-2] == 0);
        int next_valid = (i + 1) < size;
        int next_small = next_valid && (src[i+1] < 4);

        if (condition && next_valid && next_small) {
            dst[dsize++] = src[i+1];
            i++; // Skip next index logically
        } else {
            dst[dsize++] = val;
        }
    }
}
