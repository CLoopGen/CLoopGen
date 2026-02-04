#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[46];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize computations to access left and top in consecutive order
    // and store v in a more sequential manner where possible.
    uint8_t temp_left[18];
    uint8_t temp_top[16];
    
    // Preload left[i], left[i+1], left[i+2] into temporary consecutive array
    for (int j = 0; j < 18; j++) {
        temp_left[j] = left[j];
    }
    // Preload top[i-1], top[i], top[i+1] with offset handling
    for (int j = 0; j < 16; j++) {
        temp_top[j] = (j >= 1) ? top[j - 1 + 0] : top[0]; // shift index to avoid negative
    }

    for (i = 0; i < 14; i++) {
        // Access left values consecutively from preloaded buffer
        uint8_t l0 = temp_left[i + 0];
        uint8_t l1 = temp_left[i + 1];
        uint8_t l2 = temp_left[i + 2];

        // Store v[2*i] and v[2*i+1] consecutively
        v[i * 2 + 0] = (l1 + l0 + 1) >> 1;
        v[i * 2 + 1] = (l2 + l1 * 2 + l0 + 2) >> 2;

        // Handle top using shifted but consecutive temp_top
        if (i < 16) {
            uint8_t t0 = (i == 0) ? top[0] : temp_top[i - 1]; // top[i-1]
            uint8_t t1 = temp_top[i + 0]; // top[i]
            uint8_t t2 = (i + 1 < 16) ? top[i + 1] : top[15];

            v[32 + i] = (t0 + t1 * 2 + t2 + 2) >> 2;
        }
    }
}
