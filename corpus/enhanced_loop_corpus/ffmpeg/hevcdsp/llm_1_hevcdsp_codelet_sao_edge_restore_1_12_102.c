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
if (init_x + save_upper_left < width - save_upper_right) {
    for (x = init_x + save_upper_left; x < width - save_upper_right; x++) {
        dst[x] = src[x];
    }
} else {
    for (x = init_x + save_upper_left; x < init_x + save_upper_left; x++) {
        dst[x] = src[x];
    }
}
}
