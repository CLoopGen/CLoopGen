#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint8_t *left;
extern  int inv_angle[];
extern uint8_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    // Trip count is halved by stepping by 2, and extra operations added (bitwise and addition)
    for (x = last; x <= -1; x += 2) {
        int index = x * inv_angle[mode - 11];
        int offset = (index + (index >> 4) + 128) >> 8; // Added bit shift to increase computation
        ref_tmp[x] = left[-1 + offset];
        if (x + 1 <= -1) {
            ref_tmp[x + 1] = left[-1 + (((x + 1) * inv_angle[mode - 11] + 128) >> 8)];
        }
    }
}
