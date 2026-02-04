#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern uint8_t invert;
extern uint8_t *planep;
extern int width;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < height; y++) {
    planep += stride;
    uint8_t prev_val = planep[-stride];
    planep[0] ^= prev_val;
    for (x = 1; x < width; x++) {
        uint8_t top_val = planep[x - stride];
        uint8_t left_val = planep[x - 1];
        uint8_t diff = (top_val != left_val);
        uint8_t use_invert = ((diff & 1) ^ ((top_val + left_val) & 1)) ? invert : left_val;
        planep[x] ^= use_invert;
    }
}
}
