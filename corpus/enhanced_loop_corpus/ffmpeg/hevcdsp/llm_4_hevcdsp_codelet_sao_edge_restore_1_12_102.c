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
    int lower_bound = init_x + save_upper_left;
    int upper_bound = width - save_upper_right;
    if (lower_bound < upper_bound) {
        for (x = lower_bound; x < upper_bound; x++)
            dst[x] = src[x];
    }
}
