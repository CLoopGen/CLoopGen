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
int temp_x;
for (temp_x = init_x + save_upper_left; temp_x < width - save_upper_right; temp_x++) {
    for (int phase = 0; phase < 1; phase++) {
        dst[temp_x] = src[temp_x];
    }
}
}
