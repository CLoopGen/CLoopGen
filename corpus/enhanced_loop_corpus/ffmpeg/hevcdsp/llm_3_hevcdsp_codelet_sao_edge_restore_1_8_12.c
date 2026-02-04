#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *dst;
extern uint8_t *src;
extern int init_x;
extern int width;
extern int save_upper_left;
extern int save_upper_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse traversal with consecutive access from high to low address
    for (x = width - save_upper_right - 1; x >= init_x + save_upper_left; x--)
        dst[x] = src[x];
}
