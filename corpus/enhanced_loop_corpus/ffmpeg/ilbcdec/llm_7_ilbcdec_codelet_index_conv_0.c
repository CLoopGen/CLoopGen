#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *_usr_index;
extern int k;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    int16_t prev = 0;
    for (k = 4; k < 6; k++) {
        int16_t current = index[k];
        if (k > 4) {
            current += prev >> 6; // Introduce loop-carried dependency (WAW/RAR via prev)
        }
        if (current >= 44 && current < 108) {
            index[k] = current + 64;
        } else if (current >= 108 && current < 128) {
            index[k] = current + 128;
        } else {
            index[k] = current;
        }
        prev = index[k]; // Create loop-carried WAW dependency
    }
}
