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
    uint16_t temp;
    for (i = init_x + save_upper_left; i < width - save_upper_right; i++) {
        temp = src[i];
        dst[i] = temp;
    }
}
