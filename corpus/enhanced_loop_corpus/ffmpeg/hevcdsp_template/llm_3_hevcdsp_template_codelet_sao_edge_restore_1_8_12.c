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
    // Variant 2: Consecutive write with reverse read order
    int offset = init_x + save_upper_left;
    int count = (width - save_upper_right) - offset;
    for (int i = 0; i < count; i++) {
        dst[offset + i] = src[(width - save_upper_right) - 1 - i];
    }
}
