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
    int i;
    for (i = init_x + save_upper_left; i < width - save_upper_right; i += 2) {
        if (i + 1 < width - save_upper_right) {
            dst[i]     = src[i];
            dst[i + 1] = src[i + 1];
        } else {
            dst[i] = src[i];
        }
    }
}
