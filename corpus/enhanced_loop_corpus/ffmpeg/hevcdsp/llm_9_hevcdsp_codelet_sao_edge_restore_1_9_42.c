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
    int limit = width - save_upper_right;
    int offset = init_x + save_upper_left;
    for (x = offset; x < limit; x++) {
        uint16_t val = src[x];
        dst[x] = val;
    }
}
