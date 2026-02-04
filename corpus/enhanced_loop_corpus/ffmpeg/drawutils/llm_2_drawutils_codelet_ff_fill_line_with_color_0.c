#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t dst_color[4];
extern uint8_t rgba_color[4];
extern uint8_t rgba_map[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *d = dst_color;
    uint8_t *r = rgba_color;
    uint8_t *m = rgba_map;
    for (i = 0; i < 4; i++) {
        *(d + *(m + i)) = *(r + i);
    }
}
