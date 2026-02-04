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
    int start = init_x + save_upper_left;
    int end = width - save_upper_right;
    if (start < end) {
        for (x = start; x < end; x++)
            dst[x] = src[x];
    }
}
