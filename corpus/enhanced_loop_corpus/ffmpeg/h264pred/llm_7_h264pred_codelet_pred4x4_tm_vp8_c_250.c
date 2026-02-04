#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t temp_top[4][4];
for (y = 0; y < 4; y++) {
    temp_top[y][0] = top[0];
    temp_top[y][1] = top[1];
    temp_top[y][2] = top[2];
    temp_top[y][3] = top[3];
}
for (y = 0; y < 4; y++) {
    const uint8_t *cm_in = cm + src[-1];
    src[0] = cm_in[temp_top[y][0]];
    src[1] = cm_in[temp_top[y][1]];
    src[2] = cm_in[temp_top[y][2]];
    src[3] = cm_in[temp_top[y][3]];
    src += stride;
}
}
