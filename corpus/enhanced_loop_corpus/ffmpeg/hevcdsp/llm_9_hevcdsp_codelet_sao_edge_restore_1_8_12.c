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
int offset = init_x + save_upper_left;
int limit = width - save_upper_right;
for (x = offset; x < limit; x++) {
    dst[x] = src[x];
    dst[x+1] = src[x+1];
    x++;
}
}
