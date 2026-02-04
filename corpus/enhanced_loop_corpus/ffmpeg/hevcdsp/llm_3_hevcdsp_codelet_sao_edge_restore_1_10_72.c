#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_x;
extern int width;
extern int save_upper_left;
extern int save_upper_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write, reverse traversal of source array
    int offset = (width - save_upper_right) - (init_x + save_upper_left);
    for (x = 0; x < offset; x++) {
        int idx = (width - save_upper_right - 1) - x;
        dst[init_x + save_upper_left + x] = src[idx];
    }
}
