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
    // Variant 1: Strided memory access (access every 2nd element)
    for (x = init_x + save_upper_left; x < width - save_upper_right; x += 2)
        dst[x] = src[x];
}
